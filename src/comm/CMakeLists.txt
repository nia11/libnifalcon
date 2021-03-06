######################################################################################
# Build function for communications libraries
######################################################################################

SET(DEBUG_DEFINES FALSE)

IF(WIN32)
  SET(DEBUG_DEFINES "-DFTD2XX_WINDOWS")
ENDIF(WIN32)

IF(LIBUSB_DEBUG)
  SET(DEBUG_DEFINES "-DLIBUSB_DEBUG")
ENDIF(LIBUSB_DEBUG)

IF(LIBUSB_1_FOUND)
  SET(COMM_LIBS)
  INCLUDE_DIRECTORIES(${LIBUSB_1_INCLUDE_DIRS})
  LIST(APPEND COMM_LIBS ${LIBUSB_1_LIBRARIES} ${LIBNIFALCON_REQ_LIBS})
  SET(SRCS
	"FalconCommLibUSB.cpp" 
	"${LIBNIFALCON_INCLUDE_DIRS}/falcon/comm/FalconCommLibUSB.h"
	)
  NP_BUILD_LIB(
	NAME ${LIBNIFALCON_CPP_COMM_PREFIX}_libusb 
	SOURCES "${SRCS}"
	CXX_FLAGS "${DEBUG_DEFINES}"
	LINK_LIBS "${COMM_LIBS}" 
	LINK_FLAGS FALSE
	DEPENDS FALSE
	SHOULD_INSTALL TRUE
	VERSION ${LIBNIFALCON_VERSION}
	)
ENDIF(LIBUSB_1_FOUND)

IF(LIBFTDI_FOUND)
  SET(COMM_LIBS)
  INCLUDE_DIRECTORIES(${LIBFTDI_INCLUDE_DIRS})
  LIST(APPEND COMM_LIBS ${LIBFTDI_LIBRARIES} ${LIBNIFALCON_REQ_LIBS})
  SET(SRCS
	"FalconCommLibFTDI.cpp" 
	"${LIBNIFALCON_INCLUDE_DIRS}/falcon/comm/FalconCommLibFTDI.h"
	)
  NP_BUILD_LIB(
	NAME ${LIBNIFALCON_CPP_COMM_PREFIX}_libftdi
	SOURCES "${SRCS}"
	CXX_FLAGS "${DEBUG_DEFINES}"
	LINK_LIBS "${COMM_LIBS}" 
	LINK_FLAGS FALSE
	DEPENDS FALSE
	SHOULD_INSTALL TRUE
	VERSION ${LIBNIFALCON_VERSION}
	)
ENDIF(LIBFTDI_FOUND)

IF(LIBFTD2XX_FOUND)
  SET(COMM_LIBS)
  INCLUDE_DIRECTORIES(${LIBFTD2XX_INCLUDE_DIRS})
  LIST(APPEND COMM_LIBS ${LIBFTD2XX_LIBRARIES} ${LIBNIFALCON_REQ_LIBS})
  SET(SRCS
	"FalconCommFTD2XX.cpp" 
	"${LIBNIFALCON_INCLUDE_DIRS}/falcon/comm/FalconCommFTD2XX.h"
	)
  NP_BUILD_LIB(
	NAME ${LIBNIFALCON_CPP_COMM_PREFIX}_ftd2xx
	SOURCES "${SRCS}" 
	CXX_FLAGS "${DEBUG_DEFINES}"
	LINK_LIBS "${COMM_LIBS}" 
	LINK_FLAGS FALSE
	DEPENDS FALSE
	SHOULD_INSTALL TRUE
	VERSION ${LIBNIFALCON_VERSION}
	)
ENDIF(LIBFTD2XX_FOUND)
