# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


SET(CPACK_BINARY_7Z "")
SET(CPACK_BINARY_BUNDLE "")
SET(CPACK_BINARY_CYGWIN "")
SET(CPACK_BINARY_DEB "OFF")
SET(CPACK_BINARY_DRAGNDROP "")
SET(CPACK_BINARY_IFW "OFF")
SET(CPACK_BINARY_NSIS "OFF")
SET(CPACK_BINARY_OSXX11 "")
SET(CPACK_BINARY_PACKAGEMAKER "")
SET(CPACK_BINARY_PRODUCTBUILD "")
SET(CPACK_BINARY_RPM "OFF")
SET(CPACK_BINARY_STGZ "ON")
SET(CPACK_BINARY_TBZ2 "OFF")
SET(CPACK_BINARY_TGZ "ON")
SET(CPACK_BINARY_TXZ "OFF")
SET(CPACK_BINARY_TZ "ON")
SET(CPACK_BINARY_WIX "")
SET(CPACK_BINARY_ZIP "")
SET(CPACK_BUILD_SOURCE_DIRS "/home/michaelpollind/project/io;/home/michaelpollind/project/io/cmake-build-debug")
SET(CPACK_CMAKE_GENERATOR "Unix Makefiles")
SET(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
SET(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
SET(CPACK_GENERATOR "STGZ;TGZ;TZ")
SET(CPACK_INSTALL_CMAKE_PROJECTS "/home/michaelpollind/project/io/cmake-build-debug;IoLanguage;ALL;/")
SET(CPACK_INSTALL_PREFIX "/usr/local")
SET(CPACK_MODULE_PATH "/home/michaelpollind/project/io/modules/")
SET(CPACK_NSIS_DISPLAY_NAME "IoLanguage")
SET(CPACK_NSIS_INSTALLER_ICON_CODE "")
SET(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
SET(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
SET(CPACK_NSIS_PACKAGE_NAME "IoLanguage")
SET(CPACK_OUTPUT_CONFIG_FILE "/home/michaelpollind/project/io/cmake-build-debug/CPackConfig.cmake")
SET(CPACK_PACKAGE_CONTACT "iolanguage@yahoogroups.com")
SET(CPACK_PACKAGE_DEFAULT_LOCATION "/")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "/home/michaelpollind/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/171.4073.41/bin/cmake/share/cmake-3.7/Templates/CPack.GenericDescription.txt")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Io Language")
SET(CPACK_PACKAGE_FILE_NAME "IoLanguage-2017.05.16-Linux")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "IoLanguage")
SET(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "IoLanguage")
SET(CPACK_PACKAGE_NAME "IoLanguage")
SET(CPACK_PACKAGE_RELOCATABLE "true")
SET(CPACK_PACKAGE_VENDOR "iolanguage.com")
SET(CPACK_PACKAGE_VERSION "2017.05.16")
SET(CPACK_PACKAGE_VERSION_MAJOR "2017")
SET(CPACK_PACKAGE_VERSION_MINOR "05")
SET(CPACK_PACKAGE_VERSION_PATCH "16")
SET(CPACK_RESOURCE_FILE_LICENSE "/home/michaelpollind/project/io/license/bsd_license.txt")
SET(CPACK_RESOURCE_FILE_README "/home/michaelpollind/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/171.4073.41/bin/cmake/share/cmake-3.7/Templates/CPack.GenericDescription.txt")
SET(CPACK_RESOURCE_FILE_WELCOME "/home/michaelpollind/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/171.4073.41/bin/cmake/share/cmake-3.7/Templates/CPack.GenericWelcome.txt")
SET(CPACK_SET_DESTDIR "ON")
SET(CPACK_SOURCE_7Z "")
SET(CPACK_SOURCE_CYGWIN "")
SET(CPACK_SOURCE_GENERATOR "TBZ2;TGZ;TXZ;TZ")
SET(CPACK_SOURCE_OUTPUT_CONFIG_FILE "/home/michaelpollind/project/io/cmake-build-debug/CPackSourceConfig.cmake")
SET(CPACK_SOURCE_RPM "OFF")
SET(CPACK_SOURCE_TBZ2 "ON")
SET(CPACK_SOURCE_TGZ "ON")
SET(CPACK_SOURCE_TXZ "ON")
SET(CPACK_SOURCE_TZ "ON")
SET(CPACK_SOURCE_ZIP "OFF")
SET(CPACK_SYSTEM_NAME "Linux")
SET(CPACK_TOPLEVEL_TAG "Linux")
SET(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "/home/michaelpollind/project/io/cmake-build-debug/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
