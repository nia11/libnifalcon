/***
 * @file FalconFirmwareNovintSDK.h
 * @brief Firmware communications for the firmware included with the Novint SDK/Official Drivers
 * @author Kyle Machulis (kyle@nonpolynomial.com)
 * @copyright (c) 2007-2009 Nonpolynomial Labs/Kyle Machulis
 * @license BSD License
 *
 * Project info at http://libnifalcon.sourceforge.net/
 *
 */

#ifndef FALCONNOVINTFIRMWARE_H
#define FALCONNOVINTFIRMWARE_H

#include "falcon/core/FalconFirmware.h"
#include "falcon/core/FalconLogger.h"

namespace libnifalcon
{
	class FalconFirmwareNovintSDK : public FalconFirmware
	{
	public:
		FalconFirmwareNovintSDK();
		~FalconFirmwareNovintSDK();
		bool runIOLoop();
		int32_t getGripInfoSize() { return 1; }
		//Things I am going to hell for, #8926:
		uint8_t* getGripInfo() { return &(m_gripInfo); }
	protected:

		void formatInput();
		bool formatOutput();

		uint8_t m_gripInfo;
		uint8_t m_rawData[128];
		uint8_t m_rawInput[16], m_rawOutput[16], m_rawOutputInternal[16];

		unsigned int m_currentOutputIndex;
		unsigned int m_rawDataSize;
	private:
		DECLARE_LOGGER();

	};
}

#endif
