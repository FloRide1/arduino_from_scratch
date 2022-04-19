cmake_minimum_required(VERSION 3.00)

#### AVR #####
# Setup AVR compiler variables
set(TRIPLE "avr")

if(UNIX)
    set(OS_SUFFIX "")
    find_path(TOOLCHAIN_ROOT
        NAMES
            ${TRIPLE}-gcc${OS_SUFFIX}
        PATHS
            /usr/bin/
            /usr/local/bin
            /bin/
            $ENV{AVR_ROOT}
    )
elseif(WIN32)
    set(OS_SUFFIX ".exe")
    find_path(TOOLCHAIN_ROOT
        NAMES
            ${TRIPLE}-gcc${OS_SUFFIX}
        PATHS
            "C:\\WinAVR\\bin"
            $ENV{AVR_ROOT}
    )
else(UNIX)
    message(FATAL_ERROR "Toolchain not supported on your distribution")
endif(UNIX)

if(NOT TOOLCHAIN_ROOT)
    message(FATAL_ERROR "Toolchain root could not be found")
endif(NOT TOOLCHAIN_ROOT)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)
set(CMAKE_CROSS_COMPILING 1)

set(CMAKE_C_COMPILER   "${TOOLCHAIN_ROOT}/${TRIPLE}-gcc${OS_SUFFIX}"     CACHE PATH "gcc"     FORCE)
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_ROOT}/${TRIPLE}-g++${OS_SUFFIX}"     CACHE PATH "g++"     FORCE)
set(CMAKE_AR           "${TOOLCHAIN_ROOT}/${TRIPLE}-ar${OS_SUFFIX}"      CACHE PATH "ar"      FORCE)
set(CMAKE_LINKER       "${TOOLCHAIN_ROOT}/${TRIPLE}-ld${OS_SUFFIX}"      CACHE PATH "linker"  FORCE)
set(CMAKE_NM           "${TOOLCHAIN_ROOT}/${TRIPLE}-nm${OS_SUFFIX}"      CACHE PATH "nm"      FORCE)
set(CMAKE_OBJCOPY      "${TOOLCHAIN_ROOT}/${TRIPLE}-objcopy${OS_SUFFIX}" CACHE PATH "objcopy" FORCE)
set(CMAKE_OBJDUMP      "${TOOLCHAIN_ROOT}/${TRIPLE}-objdump${OS_SUFFIX}" CACHE PATH "objdump" FORCE)
set(CMAKE_STRIP        "${TOOLCHAIN_ROOT}/${TRIPLE}-strip${OS_SUFFIX}"   CACHE PATH "strip"   FORCE)
set(CMAKE_RANLIB       "${TOOLCHAIN_ROOT}/${TRIPLE}-ranlib${OS_SUFFIX}"  CACHE PATH "ranlib"  FORCE)
set(AVR_SIZE           "${TOOLCHAIN_ROOT}/${TRIPLE}-size${OS_SUFFIX}"    CACHE PATH "size"    FORCE)


# AVR Uploader config
find_program(AVR_UPLOAD
	NAME
		avrdude
	PATHS
		/usr/bin/
		$ENV{AVR_ROOT}
)

if(NOT AVR_UPLOAD_BAUD)
	set(AVR_UPLOAD_BAUD 115200)
endif(NOT AVR_UPLOAD_BAUD)

if(NOT AVR_UPLOAD_PROGRAMMER)
	set(AVR_UPLOAD_PROGRAMMER "arduino")
endif(NOT AVR_UPLOAD_PROGRAMMER)

if(NOT AVR_UPLOAD_PORT)
	if(UNIX)
		set(AVR_UPLOAD_PORT "/dev/ttyACM0")
	endif(UNIX)
	if(WIN32)
		set(AVR_UPLOAD_PORT "COM3")
	endif(WIN32)
endif(NOT AVR_UPLOAD_PORT)

macro(add_avr_executable target_name avr_mcu)
    set(elf_file ${target_name}-${avr_mcu}.elf)
    set(map_file ${target_name}-${avr_mcu}.map)
    set(hex_file ${target_name}-${avr_mcu}.hex)
    set(lst_file ${target_name}-${avr_mcu}.lst)

    # create ELF file
    add_executable(${elf_file} ${ARGN})

    set_target_properties(
        ${elf_file}
        PROPERTIES
            COMPILE_FLAGS "-mmcu=${avr_mcu} -g -Os -w -std=c99 -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics"
            LINK_FLAGS    "-mmcu=${avr_mcu} -Wl,-Map,${map_file} ${AVR_LINKER_LIBS}"
    )

    # Generate the LST file
    add_custom_command(
        OUTPUT ${lst_file}
        COMMAND
            ${CMAKE_OBJDUMP} -h -S ${elf_file} > ${lst_file}
        DEPENDS ${elf_file}
    )

    # Create HEX file
    add_custom_command(
        OUTPUT ${hex_file}
        COMMAND
            ${CMAKE_OBJCOPY} -j .text -j .data -O ihex ${elf_file} ${hex_file}
        DEPENDS ${elf_file}
    )

    add_custom_command(OUTPUT "print-size-${elf_file}" COMMAND ${AVR_SIZE} ${elf_file} DEPENDS ${elf_file})

    # Build the Intel HEX file for the device
    add_custom_target(${target_name} ALL DEPENDS ${hex_file} ${lst_file} "print-size-${elf_file}")
    set_target_properties(${target_name} PROPERTIES OUTPUT_NAME ${elf_file})

    # Flash command
    add_custom_command(
        OUTPUT "flash-${hex_file}"
        COMMAND
        ${AVR_UPLOAD} -b${AVR_UPLOAD_BAUD} -c${AVR_UPLOAD_PROGRAMMER} -p${avr_mcu} -U flash:w:${hex_file} -P${AVR_UPLOAD_PORT}
    )

    add_custom_target("flash" DEPENDS "flash-${hex_file}")

endmacro(add_avr_executable)


#### PROJECT ######
# Set the project name
project(a_scratch VERSION 0.1)

# Add include dir
include_directories(include)

# Get all src files (c)
file(GLOB_RECURSE SRC src/*.c)

# Clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Ouput Executable
add_avr_executable(${PROJECT_NAME} "atmega328p" ${SRC})
