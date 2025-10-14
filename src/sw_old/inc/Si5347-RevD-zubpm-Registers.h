/*
 * Si5347 Rev D Configuration Register Export Header File
 *
 * This file represents a series of Skyworks Si5347 Rev D 
 * register writes that can be performed to load a single configuration 
 * on a device. It was created by a Skyworks ClockBuilder Pro
 * export tool.
 *
 * Part:		                                       Si5347 Rev D
 * Design ID:                                          zubpm
 * Includes Pre/Post Download Control Register Writes: Yes
 * Created By:                                         ClockBuilder Pro v4.5 [2022-08-23]
 * Timestamp:                                          2025-01-08 14:54:29 GMT-05:00
 *
 * A complete design report corresponding to this export is included at the end 
 * of this header file.
 *
 */

#ifndef SI5347_REVD_REG_CONFIG_HEADER
#define SI5347_REVD_REG_CONFIG_HEADER

#define SI5347_REVD_REG_CONFIG_NUM_REGS				729

typedef struct
{
	unsigned int address; /* 16-bit register address */
	unsigned char value; /* 8-bit register data */

} si5347_revd_register_t;

si5347_revd_register_t const si5347_revd_registers[SI5347_REVD_REG_CONFIG_NUM_REGS] =
{

	/* Start configuration preamble */
	{ 0x0B24, 0xC0 },
	{ 0x0B25, 0x00 },
	/* Rev D stuck divider fix */
	{ 0x0B4E, 0x1A },
	/* End configuration preamble */

	/* Delay 300 msec */
	/*    Delay is worst case time for device to complete any calibration */
	/*    that is running due to device state change previous to this script */
	/*    being processed. */

	/* Start configuration registers */
	{ 0x0006, 0x00 },
	{ 0x0007, 0x00 },
	{ 0x0008, 0x00 },
	{ 0x000B, 0x6C },
	{ 0x0016, 0x0F },
	{ 0x0017, 0xDC },
	{ 0x0018, 0xEE },
	{ 0x0019, 0xEE },
	{ 0x001A, 0xEF },
	{ 0x0020, 0x01 },
	{ 0x002B, 0x02 },
	{ 0x002C, 0x01 },
	{ 0x002D, 0x01 },
	{ 0x002E, 0x3A },
	{ 0x002F, 0x00 },
	{ 0x0030, 0x00 },
	{ 0x0031, 0x00 },
	{ 0x0032, 0x00 },
	{ 0x0033, 0x00 },
	{ 0x0034, 0x00 },
	{ 0x0035, 0x00 },
	{ 0x0036, 0x3A },
	{ 0x0037, 0x00 },
	{ 0x0038, 0x00 },
	{ 0x0039, 0x00 },
	{ 0x003A, 0x00 },
	{ 0x003B, 0x00 },
	{ 0x003C, 0x00 },
	{ 0x003D, 0x00 },
	{ 0x003F, 0x11 },
	{ 0x0040, 0x04 },
	{ 0x0041, 0x0D },
	{ 0x0042, 0x00 },
	{ 0x0043, 0x00 },
	{ 0x0044, 0x00 },
	{ 0x0045, 0x0C },
	{ 0x0046, 0x32 },
	{ 0x0047, 0x00 },
	{ 0x0048, 0x00 },
	{ 0x0049, 0x00 },
	{ 0x004A, 0x32 },
	{ 0x004B, 0x00 },
	{ 0x004C, 0x00 },
	{ 0x004D, 0x00 },
	{ 0x004E, 0x05 },
	{ 0x004F, 0x00 },
	{ 0x0050, 0x0F },
	{ 0x0051, 0x03 },
	{ 0x0052, 0x00 },
	{ 0x0053, 0x00 },
	{ 0x0054, 0x00 },
	{ 0x0055, 0x03 },
	{ 0x0056, 0x00 },
	{ 0x0057, 0x00 },
	{ 0x0058, 0x00 },
	{ 0x0059, 0x01 },
	{ 0x005A, 0xB8 },
	{ 0x005B, 0x1E },
	{ 0x005C, 0x4D },
	{ 0x005D, 0x01 },
	{ 0x005E, 0x00 },
	{ 0x005F, 0x00 },
	{ 0x0060, 0x00 },
	{ 0x0061, 0x00 },
	{ 0x0062, 0x00 },
	{ 0x0063, 0x00 },
	{ 0x0064, 0x00 },
	{ 0x0065, 0x00 },
	{ 0x0066, 0x00 },
	{ 0x0067, 0x00 },
	{ 0x0068, 0x00 },
	{ 0x0069, 0x00 },
	{ 0x0092, 0x01 },
	{ 0x0093, 0x0A },
	{ 0x0094, 0x00 },
	{ 0x0095, 0x00 },
	{ 0x0096, 0x08 },
	{ 0x0097, 0x00 },
	{ 0x0098, 0x06 },
	{ 0x0099, 0x00 },
	{ 0x009A, 0x01 },
	{ 0x009B, 0x06 },
	{ 0x009C, 0x00 },
	{ 0x009D, 0x02 },
	{ 0x009E, 0x04 },
	{ 0x009F, 0x00 },
	{ 0x00A0, 0x02 },
	{ 0x00A1, 0x00 },
	{ 0x00A2, 0x00 },
	{ 0x00A4, 0x41 },
	{ 0x00A5, 0x60 },
	{ 0x00A6, 0x00 },
	{ 0x00A7, 0x00 },
	{ 0x00A9, 0x00 },
	{ 0x00AA, 0x00 },
	{ 0x00AB, 0x00 },
	{ 0x00AC, 0x00 },
	{ 0x00AE, 0x00 },
	{ 0x00AF, 0x00 },
	{ 0x00B0, 0x00 },
	{ 0x00B1, 0x00 },
	{ 0x00B3, 0x00 },
	{ 0x00B4, 0x00 },
	{ 0x00B5, 0x00 },
	{ 0x00B6, 0x00 },
	{ 0x00E5, 0x00 },
	{ 0x00E6, 0x0A },
	{ 0x00E7, 0x60 },
	{ 0x00E8, 0x00 },
	{ 0x00E9, 0x00 },
	{ 0x00EA, 0x00 },
	{ 0x00EB, 0x00 },
	{ 0x00EC, 0x00 },
	{ 0x00ED, 0x00 },
	{ 0x00EE, 0x00 },
	{ 0x00EF, 0x00 },
	{ 0x00F0, 0x00 },
	{ 0x00F1, 0x00 },
	{ 0x00F2, 0x00 },
	{ 0x00F3, 0x00 },
	{ 0x00F4, 0x00 },
	{ 0x00F5, 0x00 },
	{ 0x0102, 0x01 },
	{ 0x0108, 0x02 },
	{ 0x0109, 0x09 },
	{ 0x010A, 0x3E },
	{ 0x010B, 0x19 },
	{ 0x010C, 0x02 },
	{ 0x0112, 0x01 },
	{ 0x0113, 0x09 },
	{ 0x0114, 0x3B },
	{ 0x0115, 0x28 },
	{ 0x0116, 0x00 },
	{ 0x0117, 0x02 },
	{ 0x0118, 0x09 },
	{ 0x0119, 0x3B },
	{ 0x011A, 0x28 },
	{ 0x011B, 0x01 },
	{ 0x011C, 0x01 },
	{ 0x011D, 0x09 },
	{ 0x011E, 0x3B },
	{ 0x011F, 0x28 },
	{ 0x0120, 0x00 },
	{ 0x0126, 0x02 },
	{ 0x0127, 0x09 },
	{ 0x0128, 0x3B },
	{ 0x0129, 0x29 },
	{ 0x012A, 0x02 },
	{ 0x012B, 0x01 },
	{ 0x012C, 0x09 },
	{ 0x012D, 0x3B },
	{ 0x012E, 0x28 },
	{ 0x012F, 0x00 },
	{ 0x0130, 0x01 },
	{ 0x0131, 0x09 },
	{ 0x0132, 0x3B },
	{ 0x0133, 0x28 },
	{ 0x0134, 0x00 },
	{ 0x013A, 0x01 },
	{ 0x013B, 0x09 },
	{ 0x013C, 0x3B },
	{ 0x013D, 0x28 },
	{ 0x013E, 0x00 },
	{ 0x013F, 0x00 },
	{ 0x0140, 0x00 },
	{ 0x0141, 0x40 },
	{ 0x0142, 0xFF },
	{ 0x0206, 0x00 },
	{ 0x0208, 0x3F },
	{ 0x0209, 0x00 },
	{ 0x020A, 0x00 },
	{ 0x020B, 0x00 },
	{ 0x020C, 0x00 },
	{ 0x020D, 0x00 },
	{ 0x020E, 0x01 },
	{ 0x020F, 0x00 },
	{ 0x0210, 0x00 },
	{ 0x0211, 0x00 },
	{ 0x0212, 0x00 },
	{ 0x0213, 0x00 },
	{ 0x0214, 0x00 },
	{ 0x0215, 0x00 },
	{ 0x0216, 0x00 },
	{ 0x0217, 0x00 },
	{ 0x0218, 0x00 },
	{ 0x0219, 0x00 },
	{ 0x021A, 0x00 },
	{ 0x021B, 0x00 },
	{ 0x021C, 0x00 },
	{ 0x021D, 0x00 },
	{ 0x021E, 0x00 },
	{ 0x021F, 0x00 },
	{ 0x0220, 0x00 },
	{ 0x0221, 0x00 },
	{ 0x0222, 0x00 },
	{ 0x0223, 0x00 },
	{ 0x0224, 0x00 },
	{ 0x0225, 0x00 },
	{ 0x0226, 0x00 },
	{ 0x0227, 0x00 },
	{ 0x0228, 0x00 },
	{ 0x0229, 0x00 },
	{ 0x022A, 0x00 },
	{ 0x022B, 0x00 },
	{ 0x022C, 0x00 },
	{ 0x022D, 0x00 },
	{ 0x022E, 0x00 },
	{ 0x022F, 0x00 },
	{ 0x0231, 0x0B },
	{ 0x0232, 0x0B },
	{ 0x0233, 0x0B },
	{ 0x0234, 0x0B },
	{ 0x0235, 0x00 },
	{ 0x0236, 0x00 },
	{ 0x0237, 0x00 },
	{ 0x0238, 0x80 },
	{ 0x0239, 0x93 },
	{ 0x023A, 0x00 },
	{ 0x023B, 0x00 },
	{ 0x023C, 0x00 },
	{ 0x023D, 0x00 },
	{ 0x023E, 0x80 },
	{ 0x024A, 0x8B },
	{ 0x024B, 0x86 },
	{ 0x024C, 0x47 },
	{ 0x0250, 0x00 },
	{ 0x0251, 0x00 },
	{ 0x0252, 0x00 },
	{ 0x0253, 0x02 },
	{ 0x0254, 0x00 },
	{ 0x0255, 0x00 },
	{ 0x0256, 0x00 },
	{ 0x0257, 0x00 },
	{ 0x0258, 0x00 },
	{ 0x025C, 0x02 },
	{ 0x025D, 0x00 },
	{ 0x025E, 0x00 },
	{ 0x025F, 0x00 },
	{ 0x0260, 0x00 },
	{ 0x0261, 0x00 },
	{ 0x0262, 0x00 },
	{ 0x0263, 0x00 },
	{ 0x0264, 0x00 },
	{ 0x0268, 0x00 },
	{ 0x0269, 0x00 },
	{ 0x026A, 0x00 },
	{ 0x026B, 0x7A },
	{ 0x026C, 0x75 },
	{ 0x026D, 0x62 },
	{ 0x026E, 0x70 },
	{ 0x026F, 0x6D },
	{ 0x0270, 0x00 },
	{ 0x0271, 0x00 },
	{ 0x0272, 0x00 },
	{ 0x028A, 0x00 },
	{ 0x028B, 0x00 },
	{ 0x028C, 0x00 },
	{ 0x028D, 0x00 },
	{ 0x028E, 0x00 },
	{ 0x028F, 0x00 },
	{ 0x0290, 0x00 },
	{ 0x0291, 0x00 },
	{ 0x0294, 0x88 },
	{ 0x0295, 0x88 },
	{ 0x0296, 0x01 },
	{ 0x0297, 0x01 },
	{ 0x0299, 0x01 },
	{ 0x029A, 0xFA },
	{ 0x029B, 0x01 },
	{ 0x029C, 0x00 },
	{ 0x029D, 0x00 },
	{ 0x029E, 0x00 },
	{ 0x029F, 0x00 },
	{ 0x02A0, 0x00 },
	{ 0x02A1, 0x00 },
	{ 0x02A2, 0x00 },
	{ 0x02A3, 0x00 },
	{ 0x02A4, 0x00 },
	{ 0x02A5, 0x00 },
	{ 0x02A6, 0xCC },
	{ 0x02A7, 0x04 },
	{ 0x02A8, 0x00 },
	{ 0x02A9, 0x00 },
	{ 0x02AA, 0x00 },
	{ 0x02AB, 0x00 },
	{ 0x02AC, 0x00 },
	{ 0x02AD, 0x00 },
	{ 0x02AE, 0x00 },
	{ 0x02AF, 0x00 },
	{ 0x02B0, 0x00 },
	{ 0x02B1, 0x00 },
	{ 0x02B7, 0xFF },
	{ 0x0302, 0x00 },
	{ 0x0303, 0x00 },
	{ 0x0304, 0x80 },
	{ 0x0305, 0x67 },
	{ 0x0306, 0x0E },
	{ 0x0307, 0x00 },
	{ 0x0308, 0x00 },
	{ 0x0309, 0x00 },
	{ 0x030A, 0x30 },
	{ 0x030B, 0xC3 },
	{ 0x030C, 0x00 },
	{ 0x030D, 0x00 },
	{ 0x030E, 0x00 },
	{ 0x030F, 0x00 },
	{ 0x0310, 0xC0 },
	{ 0x0311, 0x0E },
	{ 0x0312, 0x00 },
	{ 0x0313, 0x00 },
	{ 0x0314, 0x00 },
	{ 0x0315, 0x00 },
	{ 0x0316, 0xFA },
	{ 0x0317, 0x00 },
	{ 0x0318, 0x00 },
	{ 0x0319, 0x00 },
	{ 0x031A, 0x00 },
	{ 0x031B, 0x00 },
	{ 0x031C, 0x00 },
	{ 0x031D, 0x00 },
	{ 0x031E, 0x00 },
	{ 0x031F, 0x00 },
	{ 0x0320, 0x00 },
	{ 0x0321, 0x00 },
	{ 0x0322, 0x00 },
	{ 0x0323, 0x00 },
	{ 0x0324, 0x00 },
	{ 0x0325, 0x00 },
	{ 0x0326, 0x00 },
	{ 0x0327, 0x00 },
	{ 0x0328, 0x00 },
	{ 0x0329, 0x00 },
	{ 0x032A, 0x00 },
	{ 0x032B, 0x00 },
	{ 0x032C, 0x00 },
	{ 0x032D, 0x00 },
	{ 0x0338, 0x00 },
	{ 0x033B, 0x00 },
	{ 0x033C, 0x00 },
	{ 0x033D, 0x00 },
	{ 0x033E, 0x00 },
	{ 0x033F, 0x00 },
	{ 0x0340, 0x00 },
	{ 0x0341, 0x00 },
	{ 0x0342, 0x00 },
	{ 0x0343, 0x00 },
	{ 0x0344, 0x00 },
	{ 0x0345, 0x00 },
	{ 0x0346, 0x00 },
	{ 0x0347, 0x00 },
	{ 0x0348, 0x00 },
	{ 0x0349, 0x00 },
	{ 0x034A, 0x00 },
	{ 0x034B, 0x00 },
	{ 0x034C, 0x00 },
	{ 0x034D, 0x00 },
	{ 0x034E, 0x00 },
	{ 0x034F, 0x00 },
	{ 0x0350, 0x00 },
	{ 0x0351, 0x00 },
	{ 0x0352, 0x00 },
	{ 0x0408, 0x0F },
	{ 0x0409, 0x21 },
	{ 0x040A, 0x09 },
	{ 0x040B, 0x08 },
	{ 0x040C, 0x3F },
	{ 0x040D, 0x3F },
	{ 0x040E, 0x0F },
	{ 0x040F, 0x23 },
	{ 0x0410, 0x09 },
	{ 0x0411, 0x08 },
	{ 0x0412, 0x3F },
	{ 0x0413, 0x3F },
	{ 0x0415, 0x00 },
	{ 0x0416, 0x00 },
	{ 0x0417, 0x00 },
	{ 0x0418, 0x00 },
	{ 0x0419, 0xBD },
	{ 0x041A, 0x00 },
	{ 0x041B, 0x00 },
	{ 0x041C, 0x00 },
	{ 0x041D, 0x00 },
	{ 0x041E, 0x00 },
	{ 0x041F, 0x80 },
	{ 0x0421, 0x2B },
	{ 0x0422, 0x01 },
	{ 0x0423, 0x00 },
	{ 0x0424, 0x00 },
	{ 0x0425, 0x00 },
	{ 0x0426, 0x00 },
	{ 0x0427, 0x00 },
	{ 0x0428, 0x00 },
	{ 0x0429, 0x00 },
	{ 0x042A, 0x00 },
	{ 0x042B, 0x01 },
	{ 0x042C, 0x87 },
	{ 0x042D, 0x03 },
	{ 0x042E, 0x19 },
	{ 0x042F, 0x19 },
	{ 0x0431, 0x00 },
	{ 0x0432, 0x49 },
	{ 0x0433, 0x03 },
	{ 0x0434, 0x00 },
	{ 0x0435, 0x00 },
	{ 0x0436, 0x04 },
	{ 0x0437, 0x00 },
	{ 0x0438, 0x00 },
	{ 0x0439, 0x00 },
	{ 0x043A, 0x02 },
	{ 0x043B, 0x03 },
	{ 0x043C, 0x00 },
	{ 0x043D, 0x0E },
	{ 0x043E, 0x06 },
	{ 0x0442, 0x00 },
	{ 0x0443, 0x00 },
	{ 0x0444, 0x00 },
	{ 0x0445, 0x00 },
	{ 0x0489, 0x0D },
	{ 0x048A, 0x00 },
	{ 0x049B, 0xF8 },
	{ 0x049D, 0x0F },
	{ 0x049E, 0x23 },
	{ 0x049F, 0x09 },
	{ 0x04A0, 0x08 },
	{ 0x04A1, 0x3F },
	{ 0x04A2, 0x3F },
	{ 0x04A6, 0x03 },
	{ 0x0508, 0x00 },
	{ 0x0509, 0x00 },
	{ 0x050A, 0x00 },
	{ 0x050B, 0x00 },
	{ 0x050C, 0x00 },
	{ 0x050D, 0x00 },
	{ 0x050E, 0x00 },
	{ 0x050F, 0x00 },
	{ 0x0510, 0x00 },
	{ 0x0511, 0x00 },
	{ 0x0512, 0x00 },
	{ 0x0513, 0x00 },
	{ 0x0515, 0x00 },
	{ 0x0516, 0x00 },
	{ 0x0517, 0x00 },
	{ 0x0518, 0x00 },
	{ 0x0519, 0x00 },
	{ 0x051A, 0x00 },
	{ 0x051B, 0x00 },
	{ 0x051C, 0x00 },
	{ 0x051D, 0x00 },
	{ 0x051E, 0x00 },
	{ 0x051F, 0x00 },
	{ 0x0521, 0x2B },
	{ 0x0522, 0x01 },
	{ 0x0523, 0x00 },
	{ 0x0524, 0x00 },
	{ 0x0525, 0x00 },
	{ 0x0526, 0x00 },
	{ 0x0527, 0x00 },
	{ 0x0528, 0x00 },
	{ 0x0529, 0x00 },
	{ 0x052A, 0x03 },
	{ 0x052B, 0x01 },
	{ 0x052C, 0x0F },
	{ 0x052D, 0x03 },
	{ 0x052E, 0x00 },
	{ 0x052F, 0x00 },
	{ 0x0531, 0x00 },
	{ 0x0532, 0x00 },
	{ 0x0533, 0x04 },
	{ 0x0534, 0x00 },
	{ 0x0535, 0x01 },
	{ 0x0536, 0x04 },
	{ 0x0537, 0x00 },
	{ 0x0538, 0x00 },
	{ 0x0539, 0x00 },
	{ 0x053D, 0x0A },
	{ 0x053E, 0x06 },
	{ 0x0542, 0x00 },
	{ 0x0543, 0x00 },
	{ 0x0544, 0x00 },
	{ 0x0545, 0x00 },
	{ 0x0589, 0x0C },
	{ 0x058A, 0x00 },
	{ 0x059B, 0x18 },
	{ 0x059D, 0x00 },
	{ 0x059E, 0x00 },
	{ 0x059F, 0x00 },
	{ 0x05A0, 0x00 },
	{ 0x05A1, 0x00 },
	{ 0x05A2, 0x00 },
	{ 0x05A6, 0x00 },
	{ 0x0602, 0x01 },
	{ 0x0608, 0x00 },
	{ 0x0609, 0x00 },
	{ 0x060A, 0x00 },
	{ 0x060B, 0x00 },
	{ 0x060C, 0x00 },
	{ 0x060D, 0x00 },
	{ 0x060E, 0x00 },
	{ 0x060F, 0x00 },
	{ 0x0610, 0x00 },
	{ 0x0611, 0x00 },
	{ 0x0612, 0x00 },
	{ 0x0613, 0x00 },
	{ 0x0615, 0x00 },
	{ 0x0616, 0x00 },
	{ 0x0617, 0x00 },
	{ 0x0618, 0x00 },
	{ 0x0619, 0x00 },
	{ 0x061A, 0x00 },
	{ 0x061B, 0x00 },
	{ 0x061C, 0x00 },
	{ 0x061D, 0x00 },
	{ 0x061E, 0x00 },
	{ 0x061F, 0x00 },
	{ 0x0621, 0x2B },
	{ 0x0622, 0x01 },
	{ 0x0623, 0x00 },
	{ 0x0624, 0x00 },
	{ 0x0625, 0x00 },
	{ 0x0626, 0x00 },
	{ 0x0627, 0x00 },
	{ 0x0628, 0x00 },
	{ 0x0629, 0x00 },
	{ 0x062A, 0x00 },
	{ 0x062B, 0x01 },
	{ 0x062C, 0x0F },
	{ 0x062D, 0x03 },
	{ 0x062E, 0x00 },
	{ 0x062F, 0x00 },
	{ 0x0631, 0x00 },
	{ 0x0632, 0x00 },
	{ 0x0633, 0x04 },
	{ 0x0634, 0x00 },
	{ 0x0636, 0x06 },
	{ 0x0637, 0x00 },
	{ 0x0638, 0x00 },
	{ 0x0639, 0x00 },
	{ 0x063D, 0x0A },
	{ 0x063E, 0x06 },
	{ 0x0689, 0x0C },
	{ 0x068A, 0x00 },
	{ 0x069B, 0x18 },
	{ 0x069D, 0x00 },
	{ 0x069E, 0x00 },
	{ 0x069F, 0x00 },
	{ 0x06A0, 0x00 },
	{ 0x06A1, 0x00 },
	{ 0x06A2, 0x00 },
	{ 0x06A6, 0x00 },
	{ 0x0702, 0x01 },
	{ 0x0709, 0x00 },
	{ 0x070A, 0x00 },
	{ 0x070B, 0x00 },
	{ 0x070C, 0x00 },
	{ 0x070D, 0x00 },
	{ 0x070E, 0x00 },
	{ 0x070F, 0x00 },
	{ 0x0710, 0x00 },
	{ 0x0711, 0x00 },
	{ 0x0712, 0x00 },
	{ 0x0713, 0x00 },
	{ 0x0714, 0x00 },
	{ 0x0716, 0x00 },
	{ 0x0717, 0x00 },
	{ 0x0718, 0x00 },
	{ 0x0719, 0x00 },
	{ 0x071A, 0x00 },
	{ 0x071B, 0x00 },
	{ 0x071C, 0x00 },
	{ 0x071D, 0x00 },
	{ 0x071E, 0x00 },
	{ 0x071F, 0x00 },
	{ 0x0720, 0x00 },
	{ 0x0722, 0x2B },
	{ 0x0723, 0x01 },
	{ 0x0724, 0x00 },
	{ 0x0725, 0x00 },
	{ 0x0726, 0x00 },
	{ 0x0727, 0x00 },
	{ 0x0728, 0x00 },
	{ 0x0729, 0x00 },
	{ 0x072A, 0x00 },
	{ 0x072B, 0x00 },
	{ 0x072C, 0x01 },
	{ 0x072D, 0x0F },
	{ 0x072E, 0x03 },
	{ 0x072F, 0x00 },
	{ 0x0730, 0x00 },
	{ 0x0732, 0x00 },
	{ 0x0733, 0x00 },
	{ 0x0734, 0x04 },
	{ 0x0735, 0x00 },
	{ 0x0737, 0x06 },
	{ 0x0738, 0x00 },
	{ 0x0739, 0x00 },
	{ 0x073A, 0x00 },
	{ 0x073E, 0x0A },
	{ 0x073F, 0x06 },
	{ 0x0789, 0x0C },
	{ 0x078A, 0x00 },
	{ 0x079B, 0x18 },
	{ 0x079D, 0x00 },
	{ 0x079E, 0x00 },
	{ 0x079F, 0x00 },
	{ 0x07A0, 0x00 },
	{ 0x07A1, 0x00 },
	{ 0x07A2, 0x00 },
	{ 0x07A6, 0x00 },
	{ 0x0802, 0x35 },
	{ 0x0803, 0x04 },
	{ 0x0804, 0x00 },
	{ 0x0805, 0x45 },
	{ 0x0806, 0x04 },
	{ 0x0807, 0x00 },
	{ 0x0808, 0x42 },
	{ 0x0809, 0x04 },
	{ 0x080A, 0x00 },
	{ 0x080B, 0x43 },
	{ 0x080C, 0x04 },
	{ 0x080D, 0x00 },
	{ 0x080E, 0x44 },
	{ 0x080F, 0x04 },
	{ 0x0810, 0x00 },
	{ 0x0811, 0x35 },
	{ 0x0812, 0x05 },
	{ 0x0813, 0x01 },
	{ 0x0814, 0x45 },
	{ 0x0815, 0x05 },
	{ 0x0816, 0x00 },
	{ 0x0817, 0x42 },
	{ 0x0818, 0x05 },
	{ 0x0819, 0x00 },
	{ 0x081A, 0x43 },
	{ 0x081B, 0x05 },
	{ 0x081C, 0x00 },
	{ 0x081D, 0x44 },
	{ 0x081E, 0x05 },
	{ 0x081F, 0x00 },
	{ 0x0820, 0x00 },
	{ 0x0821, 0x00 },
	{ 0x0822, 0x00 },
	{ 0x0823, 0x00 },
	{ 0x0824, 0x00 },
	{ 0x0825, 0x00 },
	{ 0x0826, 0x00 },
	{ 0x0827, 0x00 },
	{ 0x0828, 0x00 },
	{ 0x0829, 0x00 },
	{ 0x082A, 0x00 },
	{ 0x082B, 0x00 },
	{ 0x082C, 0x00 },
	{ 0x082D, 0x00 },
	{ 0x082E, 0x00 },
	{ 0x082F, 0x00 },
	{ 0x0830, 0x00 },
	{ 0x0831, 0x00 },
	{ 0x0832, 0x00 },
	{ 0x0833, 0x00 },
	{ 0x0834, 0x00 },
	{ 0x0835, 0x00 },
	{ 0x0836, 0x00 },
	{ 0x0837, 0x00 },
	{ 0x0838, 0x00 },
	{ 0x0839, 0x00 },
	{ 0x083A, 0x00 },
	{ 0x083B, 0x00 },
	{ 0x083C, 0x00 },
	{ 0x083D, 0x00 },
	{ 0x083E, 0x00 },
	{ 0x083F, 0x00 },
	{ 0x0840, 0x00 },
	{ 0x0841, 0x00 },
	{ 0x0842, 0x00 },
	{ 0x0843, 0x00 },
	{ 0x0844, 0x00 },
	{ 0x0845, 0x00 },
	{ 0x0846, 0x00 },
	{ 0x0847, 0x00 },
	{ 0x0848, 0x00 },
	{ 0x0849, 0x00 },
	{ 0x084A, 0x00 },
	{ 0x084B, 0x00 },
	{ 0x084C, 0x00 },
	{ 0x084D, 0x00 },
	{ 0x084E, 0x00 },
	{ 0x084F, 0x00 },
	{ 0x0850, 0x00 },
	{ 0x0851, 0x00 },
	{ 0x0852, 0x00 },
	{ 0x0853, 0x00 },
	{ 0x0854, 0x00 },
	{ 0x0855, 0x00 },
	{ 0x0856, 0x00 },
	{ 0x0857, 0x00 },
	{ 0x0858, 0x00 },
	{ 0x0859, 0x00 },
	{ 0x085A, 0x00 },
	{ 0x085B, 0x00 },
	{ 0x085C, 0x00 },
	{ 0x085D, 0x00 },
	{ 0x085E, 0x00 },
	{ 0x085F, 0x00 },
	{ 0x0860, 0x00 },
	{ 0x0861, 0x00 },
	{ 0x090E, 0x02 },
	{ 0x0943, 0x01 },
	{ 0x0949, 0x01 },
	{ 0x094A, 0x01 },
	{ 0x094E, 0x49 },
	{ 0x094F, 0x02 },
	{ 0x095E, 0x00 },
	{ 0x0A03, 0x03 },
	{ 0x0A04, 0x00 },
	{ 0x0A05, 0x03 },
	{ 0x0B44, 0x1F },
	{ 0x0B45, 0x0C },
	{ 0x0B46, 0x00 },
	{ 0x0B47, 0x0E },
	{ 0x0B48, 0x0E },
	{ 0x0B4A, 0x0C },
	{ 0x0B57, 0x0E },
	{ 0x0B58, 0x01 },
	/* End configuration registers */

	/* Start configuration postamble */
	{ 0x0414, 0x01 },
	{ 0x001C, 0x01 },
	{ 0x0B24, 0xC3 },
	{ 0x0B25, 0x02 },
	/* End configuration postamble */

};

/*
 * Design Report
 *
 * Overview
 * ========
 * Part:               Si5347AB Rev D
 * Project File:       R:\pcb\zudfe\Si5347-RevD-zubpm.slabtimeproj
 * Design ID:          zubpm
 * Created By:         ClockBuilder Pro v4.5 [2022-08-23]
 * Timestamp:          2025-01-08 14:54:29 GMT-05:00
 * 
 * Design Rule Check
 * =================
 * Errors:
 * - No errors
 * 
 * Warnings:
 * - OUT0: frequency less than 300 kHz [1]
 * 
 * Footnotes:
 * [1] AC-coupled output clocks less than 300 kHz will be significantly attenuated when using 0.1 \B5F coupling capacitors as generally installed on Skyworks customer evaluation boards. To properly observe a clock with an output frequency <= 300 kHz, the output clock AC-coupling capacitor will need to be replaced with either a higher value capacitor or with a 0 ? resistor.
 * 
 * Device Grade
 * ============
 * Maximum Output Frequency: 156.25 MHz
 * Frequency Synthesis Mode: Fractional
 * Frequency Plan Grade:     B
 * Minimum Base OPN:         Si5347B*
 * 
 * Device      Output Clock
 * Grade       Frequency Range       Typical Jitter
 * ---------   -------------------   --------------
 * Si5347A     100 Hz to 720 MHz     < 150 fs
 * Si5347B*    100 Hz to 350 MHz     "
 * 
 * * Based on your calculated frequency plan, a Si5347B grade device is
 * sufficient for your design. For more in-system configuration flexibility
 * (higher frequencies), consider selecting device grade Si5347A when
 * specifying an ordering part number (OPN) for your application. See the
 * datasheet Ordering Guide for more information.
 * 
 * Design
 * ======
 * Host Interface:
 *    I/O Power Supply: VDDA (3.3V)
 *    SPI Mode: 4-Wire
 *    I2C Address Range: 108d to 111d / 0x6C to 0x6F (selected via A0/A1 pins)
 * 
 * XA/XB:
 *    48 MHz (XTAL - Crystal)
 * 
 * Inputs:
 *     IN0: 124.92 MHz
 *          Standard
 *          DSPLL A
 *     IN1: Unused
 *     IN2: Unused
 *     IN3: Unused
 * 
 * Outputs:
 *    OUT0: 100 Hz
 *          Enabled, LVDS 1.8 V
 *          DSPLL B (Free Run)
 *    OUT1: Unused
 *    OUT2: 124.92 MHz
 *          Enabled, LVDS 2.5 V
 *          DSPLL A
 *    OUT3: Unused
 *    OUT4: 156.25 MHz
 *          Enabled, LVDS 2.5 V
 *          DSPLL B (Free Run)
 *    OUT5: Unused
 *    OUT6: Unused
 *    OUT7: Unused
 * 
 * Frequency Plan
 * ==============
 * Fvco = 14.16 GHz
 * MXAXB = 295
 * 
 * DSPLL A:
 *    Fpfd = 1.9828571428571428... MHz [ 1 + 172/175 MHz ]
 *    Fdco = 749.52 MHz
 *    I/O Delay not enabled
 *    MA = 378
 *    N0 = 18.8920909382004482... [ 18 + 2786/3123 ]
 *    Nominal Bandwidth:
 *      Desired: 1.000 kHz
 *      Actual:  637.697 Hz
 *      Coefficients:
 *         BW0:  15
 *         BW1:  33
 *         BW2:  9
 *         BW3:  8
 *         BW4:  63
 *         BW5:  63
 *    Fastlock Bandwidth:
 *      Desired: 1.000 kHz
 *      Actual:  637.697 Hz
 *      Coefficients:
 *         BW0:  15
 *         BW1:  35
 *         BW2:  9
 *         BW3:  8
 *         BW4:  63
 *         BW5:  63
 *    Holdover Bandwidth:
 *       N/A (Ramped Exit from Holdover)
 * DSPLL B:
 *    Free run only mode enabled
 *    Fdco = 937.5 MHz
 * DSPLL C is not used
 * DSPLL D is not used
 * 
 * P dividers:
 *    P0  = 63
 *    P1  = Unused
 *    P2  = Unused
 *    P3  = Unused
 *    Pxaxb = 1
 * 
 * R dividers:
 *    R0 = 9375000
 *    R1 = Unused
 *    R2 = 6
 *    R3 = Unused
 *    R4 = 6
 *    R5 = Unused
 *    R6 = Unused
 *    R7 = Unused
 * 
 * Dividers listed above show effective values. These values are translated to register settings by ClockBuilder Pro. For the actual register values, see below. Refer to the Family Reference Manual for information on registers related to frequency plan.
 * 
 * Digitally Controlled Oscillator (DCO)
 * =====================================
 * Mode: Register Direct Write
 * 
 * DSPLL A: DCO Disabled
 * 
 * DSPLL B: DCO Not Supported
 * 
 * DSPLL C: DCO Disabled
 * 
 * DSPLL D: DCO Disabled
 * 
 * Estimated Power & Junction Temperature
 * ======================================
 * Assumptions:
 * 
 * Revision: D
 * VDD:      1.8 V
 * Ta:       25 \B0C
 * Theta-JA: 18.3 \B0C/W
 * Airflow:  2 m/s
 * 
 * Total Power: 822 mW, On Chip Power: 804 mW, Tj: 40 \B0C
 * 
 *          Frequency  Format   Voltage   Current     Power
 *         ----------  ------  --------  --------  --------
 * VDD                            1.8 V  179.6 mA    323 mW
 * VDDA                           3.3 V  119.1 mA    393 mW
 * VDDO0       100 Hz  LVDS       1.8 V   15.0 mA     27 mW
 * VDDO1       Unused                                      
 * VDDO2   124.92 MHz  LVDS       2.5 V   15.6 mA     39 mW
 * VDDO3       Unused                                      
 * VDDO4   156.25 MHz  LVDS       2.5 V   15.7 mA     39 mW
 * VDDO5       Unused                                      
 * VDDO6       Unused                                      
 * VDDO7       Unused                                      
 *                                       --------  --------
 *                                Total  345.0 mA    822 mW
 * 
 * Note:
 * 
 * -Tj is junction temperature. Tj must be less than 125 \B0C (on Si5347 Revision D) for device to comply with datasheet specifications. Tj = Ta + Theta_JA*On_Chip_Power.
 * -Overall power includes on-chip power dissipation and adds differential load power dissipation to estimate total power requirements.
 * -Above are estimates only: power and temperature should be measured on your PCB.
 * -Selection of appropriate Theta-JA is required for most accurate estimate. Ideally, select 'User Specified Theta-JA' and enter a Theta-JA value based on the thermal properties of your PCB.
 * 
 * Settings
 * ========
 * 
 * Location      Setting Name                Decimal Value      Hex Value        
 * ------------  --------------------------  -----------------  -----------------
 * 0x0006[23:0]  TOOL_VERSION                0                  0x000000         
 * 0x000B[6:0]   I2C_ADDR                    108                0x6C             
 * 0x0016[0]     LOL_ON_HOLD_PLLA            1                  0x1              
 * 0x0016[1]     LOL_ON_HOLD_PLLB            1                  0x1              
 * 0x0016[2]     LOL_ON_HOLD_PLLC            1                  0x1              
 * 0x0016[3]     LOL_ON_HOLD_PLLD            1                  0x1              
 * 0x0017[0]     SYSINCAL_INTR_MSK           0                  0x0              
 * 0x0017[1]     LOSXAXB_INTR_MSK            0                  0x0              
 * 0x0017[2]     LOSREF_INTR_MSK             1                  0x1              
 * 0x0017[3]     XAXB_ERR_INTR_MSK           1                  0x1              
 * 0x0017[5]     SMB_TMOUT_INTR_MSK          0                  0x0              
 * 0x0018[3:0]   LOS_INTR_MSK                14                 0xE              
 * 0x0018[7:4]   OOF_INTR_MSK                14                 0xE              
 * 0x0019[0]     LOL_INTR_MSK_PLLA           0                  0x0              
 * 0x0019[1]     LOL_INTR_MSK_PLLB           1                  0x1              
 * 0x0019[2]     LOL_INTR_MSK_PLLC           1                  0x1              
 * 0x0019[3]     LOL_INTR_MSK_PLLD           1                  0x1              
 * 0x0019[4]     HOLD_INTR_MSK_PLLA          0                  0x0              
 * 0x0019[5]     HOLD_INTR_MSK_PLLB          1                  0x1              
 * 0x0019[6]     HOLD_INTR_MSK_PLLC          1                  0x1              
 * 0x0019[7]     HOLD_INTR_MSK_PLLD          1                  0x1              
 * 0x001A[4]     CAL_INTR_MSK_PLLA           0                  0x0              
 * 0x001A[5]     CAL_INTR_MSK_PLLB           1                  0x1              
 * 0x001A[6]     CAL_INTR_MSK_PLLC           1                  0x1              
 * 0x001A[7]     CAL_INTR_MSK_PLLD           1                  0x1              
 * 0x0020[0]     FSTEP_PLL_SINGLE            1                  0x1              
 * 0x0020[1]     FSTEP_PLL_REGCTRL           0                  0x0              
 * 0x0020[3:2]   FSTEP_PLL                   0                  0x0              
 * 0x002B[3]     SPI_3WIRE                   0                  0x0              
 * 0x002C[3:0]   LOS_EN                      1                  0x1              
 * 0x002C[4]     LOSXAXB_DIS                 0                  0x0              
 * 0x002D[1:0]   LOS0_VAL_TIME               1                  0x1              
 * 0x002D[3:2]   LOS1_VAL_TIME               0                  0x0              
 * 0x002D[5:4]   LOS2_VAL_TIME               0                  0x0              
 * 0x002D[7:6]   LOS3_VAL_TIME               0                  0x0              
 * 0x002E[15:0]  LOS0_TRG_THR                58                 0x003A           
 * 0x0030[15:0]  LOS1_TRG_THR                0                  0x0000           
 * 0x0032[15:0]  LOS2_TRG_THR                0                  0x0000           
 * 0x0034[15:0]  LOS3_TRG_THR                0                  0x0000           
 * 0x0036[15:0]  LOS0_CLR_THR                58                 0x003A           
 * 0x0038[15:0]  LOS1_CLR_THR                0                  0x0000           
 * 0x003A[15:0]  LOS2_CLR_THR                0                  0x0000           
 * 0x003C[15:0]  LOS3_CLR_THR                0                  0x0000           
 * 0x003F[3:0]   OOF_EN                      1                  0x1              
 * 0x003F[7:4]   FAST_OOF_EN                 1                  0x1              
 * 0x0040[2:0]   OOF_REF_SEL                 4                  0x4              
 * 0x0041[4:0]   OOF0_DIV_SEL                13                 0x0D             
 * 0x0042[4:0]   OOF1_DIV_SEL                0                  0x00             
 * 0x0043[4:0]   OOF2_DIV_SEL                0                  0x00             
 * 0x0044[4:0]   OOF3_DIV_SEL                0                  0x00             
 * 0x0045[4:0]   OOFXO_DIV_SEL               12                 0x0C             
 * 0x0046[7:0]   OOF0_SET_THR                50                 0x32             
 * 0x0047[7:0]   OOF1_SET_THR                0                  0x00             
 * 0x0048[7:0]   OOF2_SET_THR                0                  0x00             
 * 0x0049[7:0]   OOF3_SET_THR                0                  0x00             
 * 0x004A[7:0]   OOF0_CLR_THR                50                 0x32             
 * 0x004B[7:0]   OOF1_CLR_THR                0                  0x00             
 * 0x004C[7:0]   OOF2_CLR_THR                0                  0x00             
 * 0x004D[7:0]   OOF3_CLR_THR                0                  0x00             
 * 0x004E[2:0]   OOF0_DETWIN_SEL             5                  0x5              
 * 0x004E[6:4]   OOF1_DETWIN_SEL             0                  0x0              
 * 0x004F[2:0]   OOF2_DETWIN_SEL             0                  0x0              
 * 0x004F[6:4]   OOF3_DETWIN_SEL             0                  0x0              
 * 0x0050[3:0]   OOF_ON_LOS                  15                 0xF              
 * 0x0051[3:0]   FAST_OOF0_SET_THR           3                  0x3              
 * 0x0052[3:0]   FAST_OOF1_SET_THR           0                  0x0              
 * 0x0053[3:0]   FAST_OOF2_SET_THR           0                  0x0              
 * 0x0054[3:0]   FAST_OOF3_SET_THR           0                  0x0              
 * 0x0055[3:0]   FAST_OOF0_CLR_THR           3                  0x3              
 * 0x0056[3:0]   FAST_OOF1_CLR_THR           0                  0x0              
 * 0x0057[3:0]   FAST_OOF2_CLR_THR           0                  0x0              
 * 0x0058[3:0]   FAST_OOF3_CLR_THR           0                  0x0              
 * 0x0059[1:0]   FAST_OOF0_DETWIN_SEL        1                  0x1              
 * 0x0059[3:2]   FAST_OOF1_DETWIN_SEL        0                  0x0              
 * 0x0059[5:4]   FAST_OOF2_DETWIN_SEL        0                  0x0              
 * 0x0059[7:6]   FAST_OOF3_DETWIN_SEL        0                  0x0              
 * 0x005A[25:0]  OOF0_RATIO_REF              21831352           0x14D1EB8        
 * 0x005E[25:0]  OOF1_RATIO_REF              0                  0x0000000        
 * 0x0062[25:0]  OOF2_RATIO_REF              0                  0x0000000        
 * 0x0066[25:0]  OOF3_RATIO_REF              0                  0x0000000        
 * 0x0092[0]     LOL_FST_EN_PLLA             1                  0x1              
 * 0x0092[1]     LOL_FST_EN_PLLB             0                  0x0              
 * 0x0092[2]     LOL_FST_EN_PLLC             0                  0x0              
 * 0x0092[3]     LOL_FST_EN_PLLD             0                  0x0              
 * 0x0093[3:0]   LOL_FST_DETWIN_SEL_PLLA     10                 0xA              
 * 0x0093[7:4]   LOL_FST_DETWIN_SEL_PLLB     0                  0x0              
 * 0x0094[3:0]   LOL_FST_DETWIN_SEL_PLLC     0                  0x0              
 * 0x0094[7:4]   LOL_FST_DETWIN_SEL_PLLD     0                  0x0              
 * 0x0095[1:0]   LOL_FST_VALWIN_SEL_PLLA     0                  0x0              
 * 0x0095[3:2]   LOL_FST_VALWIN_SEL_PLLB     0                  0x0              
 * 0x0095[5:4]   LOL_FST_VALWIN_SEL_PLLC     0                  0x0              
 * 0x0095[7:6]   LOL_FST_VALWIN_SEL_PLLD     0                  0x0              
 * 0x0096[3:0]   LOL_FST_SET_THR_SEL_PLLA    8                  0x8              
 * 0x0096[7:4]   LOL_FST_SET_THR_SEL_PLLB    0                  0x0              
 * 0x0097[3:0]   LOL_FST_SET_THR_SEL_PLLC    0                  0x0              
 * 0x0097[7:4]   LOL_FST_SET_THR_SEL_PLLD    0                  0x0              
 * 0x0098[3:0]   LOL_FST_CLR_THR_SEL_PLLA    6                  0x6              
 * 0x0098[7:4]   LOL_FST_CLR_THR_SEL_PLLB    0                  0x0              
 * 0x0099[3:0]   LOL_FST_CLR_THR_SEL_PLLC    0                  0x0              
 * 0x0099[7:4]   LOL_FST_CLR_THR_SEL_PLLD    0                  0x0              
 * 0x009A[0]     LOL_SLOW_EN_PLLA            1                  0x1              
 * 0x009A[1]     LOL_SLOW_EN_PLLB            0                  0x0              
 * 0x009A[2]     LOL_SLOW_EN_PLLC            0                  0x0              
 * 0x009A[3]     LOL_SLOW_EN_PLLD            0                  0x0              
 * 0x009B[3:0]   LOL_SLW_DETWIN_SEL_PLLA     6                  0x6              
 * 0x009B[7:4]   LOL_SLW_DETWIN_SEL_PLLB     0                  0x0              
 * 0x009C[3:0]   LOL_SLW_DETWIN_SEL_PLLC     0                  0x0              
 * 0x009C[7:4]   LOL_SLW_DETWIN_SEL_PLLD     0                  0x0              
 * 0x009D[1:0]   LOL_SLW_VALWIN_SEL_PLLA     2                  0x2              
 * 0x009D[3:2]   LOL_SLW_VALWIN_SEL_PLLB     0                  0x0              
 * 0x009D[5:4]   LOL_SLW_VALWIN_SEL_PLLC     0                  0x0              
 * 0x009D[7:6]   LOL_SLW_VALWIN_SEL_PLLD     0                  0x0              
 * 0x009E[3:0]   LOL_SLW_SET_THR_PLLA        4                  0x4              
 * 0x009E[7:4]   LOL_SLW_SET_THR_PLLB        0                  0x0              
 * 0x009F[3:0]   LOL_SLW_SET_THR_PLLC        0                  0x0              
 * 0x009F[7:4]   LOL_SLW_SET_THR_PLLD        0                  0x0              
 * 0x00A0[3:0]   LOL_SLW_CLR_THR_PLLA        2                  0x2              
 * 0x00A0[7:4]   LOL_SLW_CLR_THR_PLLB        0                  0x0              
 * 0x00A1[3:0]   LOL_SLW_CLR_THR_PLLC        0                  0x0              
 * 0x00A1[7:4]   LOL_SLW_CLR_THR_PLLD        0                  0x0              
 * 0x00A2[0]     LOL_TIMER_EN_PLLA           0                  0x0              
 * 0x00A2[1]     LOL_TIMER_EN_PLLB           0                  0x0              
 * 0x00A2[2]     LOL_TIMER_EN_PLLC           0                  0x0              
 * 0x00A2[3]     LOL_TIMER_EN_PLLD           0                  0x0              
 * 0x00A4[28:0]  LOL_CLR_DELAY_DIV256_PLLA   24641              0x00006041       
 * 0x00A9[28:0]  LOL_CLR_DELAY_DIV256_PLLB   0                  0x00000000       
 * 0x00AE[28:0]  LOL_CLR_DELAY_DIV256_PLLC   0                  0x00000000       
 * 0x00B3[28:0]  LOL_CLR_DELAY_DIV256_PLLD   0                  0x00000000       
 * 0x00E5[0]     FASTLOCK_EXTEND_MASTER_DIS  0                  0x0              
 * 0x00E5[4]     FASTLOCK_EXTEND_EN_PLLA     0                  0x0              
 * 0x00E5[5]     FASTLOCK_EXTEND_EN_PLLB     0                  0x0              
 * 0x00E5[6]     FASTLOCK_EXTEND_EN_PLLC     0                  0x0              
 * 0x00E5[7]     FASTLOCK_EXTEND_EN_PLLD     0                  0x0              
 * 0x00E6[28:0]  FASTLOCK_EXTEND_PLLA        24586              0x0000600A       
 * 0x00EA[28:0]  FASTLOCK_EXTEND_PLLB        0                  0x00000000       
 * 0x00EE[28:0]  FASTLOCK_EXTEND_PLLC        0                  0x00000000       
 * 0x00F2[28:0]  FASTLOCK_EXTEND_PLLD        0                  0x00000000       
 * 0x0102[0]     OUTALL_DISABLE_LOW          1                  0x1              
 * 0x0108[0]     OUT0_PDN                    0                  0x0              
 * 0x0108[1]     OUT0_OE                     1                  0x1              
 * 0x0108[2]     OUT0_RDIV_FORCE2            0                  0x0              
 * 0x0109[2:0]   OUT0_FORMAT                 1                  0x1              
 * 0x0109[3]     OUT0_SYNC_EN                1                  0x1              
 * 0x0109[5:4]   OUT0_DIS_STATE              0                  0x0              
 * 0x0109[7:6]   OUT0_CMOS_DRV               0                  0x0              
 * 0x010A[3:0]   OUT0_CM                     14                 0xE              
 * 0x010A[6:4]   OUT0_AMPL                   3                  0x3              
 * 0x010B[2:0]   OUT0_MUX_SEL                1                  0x1              
 * 0x010B[5:4]   OUT0_VDD_SEL                1                  0x1              
 * 0x010B[3]     OUT0_VDD_SEL_EN             1                  0x1              
 * 0x010B[7:6]   OUT0_INV                    0                  0x0              
 * 0x010C[2:0]   OUT0_DIS_SRC                2                  0x2              
 * 0x0112[0]     OUT1_PDN                    1                  0x1              
 * 0x0112[1]     OUT1_OE                     0                  0x0              
 * 0x0112[2]     OUT1_RDIV_FORCE2            0                  0x0              
 * 0x0113[2:0]   OUT1_FORMAT                 1                  0x1              
 * 0x0113[3]     OUT1_SYNC_EN                1                  0x1              
 * 0x0113[5:4]   OUT1_DIS_STATE              0                  0x0              
 * 0x0113[7:6]   OUT1_CMOS_DRV               0                  0x0              
 * 0x0114[3:0]   OUT1_CM                     11                 0xB              
 * 0x0114[6:4]   OUT1_AMPL                   3                  0x3              
 * 0x0115[2:0]   OUT1_MUX_SEL                0                  0x0              
 * 0x0115[5:4]   OUT1_VDD_SEL                2                  0x2              
 * 0x0115[3]     OUT1_VDD_SEL_EN             1                  0x1              
 * 0x0115[7:6]   OUT1_INV                    0                  0x0              
 * 0x0116[2:0]   OUT1_DIS_SRC                0                  0x0              
 * 0x0117[0]     OUT2_PDN                    0                  0x0              
 * 0x0117[1]     OUT2_OE                     1                  0x1              
 * 0x0117[2]     OUT2_RDIV_FORCE2            0                  0x0              
 * 0x0118[2:0]   OUT2_FORMAT                 1                  0x1              
 * 0x0118[3]     OUT2_SYNC_EN                1                  0x1              
 * 0x0118[5:4]   OUT2_DIS_STATE              0                  0x0              
 * 0x0118[7:6]   OUT2_CMOS_DRV               0                  0x0              
 * 0x0119[3:0]   OUT2_CM                     11                 0xB              
 * 0x0119[6:4]   OUT2_AMPL                   3                  0x3              
 * 0x011A[2:0]   OUT2_MUX_SEL                0                  0x0              
 * 0x011A[5:4]   OUT2_VDD_SEL                2                  0x2              
 * 0x011A[3]     OUT2_VDD_SEL_EN             1                  0x1              
 * 0x011A[7:6]   OUT2_INV                    0                  0x0              
 * 0x011B[2:0]   OUT2_DIS_SRC                1                  0x1              
 * 0x011C[0]     OUT3_PDN                    1                  0x1              
 * 0x011C[1]     OUT3_OE                     0                  0x0              
 * 0x011C[2]     OUT3_RDIV_FORCE2            0                  0x0              
 * 0x011D[2:0]   OUT3_FORMAT                 1                  0x1              
 * 0x011D[3]     OUT3_SYNC_EN                1                  0x1              
 * 0x011D[5:4]   OUT3_DIS_STATE              0                  0x0              
 * 0x011D[7:6]   OUT3_CMOS_DRV               0                  0x0              
 * 0x011E[3:0]   OUT3_CM                     11                 0xB              
 * 0x011E[6:4]   OUT3_AMPL                   3                  0x3              
 * 0x011F[2:0]   OUT3_MUX_SEL                0                  0x0              
 * 0x011F[5:4]   OUT3_VDD_SEL                2                  0x2              
 * 0x011F[3]     OUT3_VDD_SEL_EN             1                  0x1              
 * 0x011F[7:6]   OUT3_INV                    0                  0x0              
 * 0x0120[2:0]   OUT3_DIS_SRC                0                  0x0              
 * 0x0126[0]     OUT4_PDN                    0                  0x0              
 * 0x0126[1]     OUT4_OE                     1                  0x1              
 * 0x0126[2]     OUT4_RDIV_FORCE2            0                  0x0              
 * 0x0127[2:0]   OUT4_FORMAT                 1                  0x1              
 * 0x0127[3]     OUT4_SYNC_EN                1                  0x1              
 * 0x0127[5:4]   OUT4_DIS_STATE              0                  0x0              
 * 0x0127[7:6]   OUT4_CMOS_DRV               0                  0x0              
 * 0x0128[3:0]   OUT4_CM                     11                 0xB              
 * 0x0128[6:4]   OUT4_AMPL                   3                  0x3              
 * 0x0129[2:0]   OUT4_MUX_SEL                1                  0x1              
 * 0x0129[5:4]   OUT4_VDD_SEL                2                  0x2              
 * 0x0129[3]     OUT4_VDD_SEL_EN             1                  0x1              
 * 0x0129[7:6]   OUT4_INV                    0                  0x0              
 * 0x012A[2:0]   OUT4_DIS_SRC                2                  0x2              
 * 0x012B[0]     OUT5_PDN                    1                  0x1              
 * 0x012B[1]     OUT5_OE                     0                  0x0              
 * 0x012B[2]     OUT5_RDIV_FORCE2            0                  0x0              
 * 0x012C[2:0]   OUT5_FORMAT                 1                  0x1              
 * 0x012C[3]     OUT5_SYNC_EN                1                  0x1              
 * 0x012C[5:4]   OUT5_DIS_STATE              0                  0x0              
 * 0x012C[7:6]   OUT5_CMOS_DRV               0                  0x0              
 * 0x012D[3:0]   OUT5_CM                     11                 0xB              
 * 0x012D[6:4]   OUT5_AMPL                   3                  0x3              
 * 0x012E[2:0]   OUT5_MUX_SEL                0                  0x0              
 * 0x012E[5:4]   OUT5_VDD_SEL                2                  0x2              
 * 0x012E[3]     OUT5_VDD_SEL_EN             1                  0x1              
 * 0x012E[7:6]   OUT5_INV                    0                  0x0              
 * 0x012F[2:0]   OUT5_DIS_SRC                0                  0x0              
 * 0x0130[0]     OUT6_PDN                    1                  0x1              
 * 0x0130[1]     OUT6_OE                     0                  0x0              
 * 0x0130[2]     OUT6_RDIV_FORCE2            0                  0x0              
 * 0x0131[2:0]   OUT6_FORMAT                 1                  0x1              
 * 0x0131[3]     OUT6_SYNC_EN                1                  0x1              
 * 0x0131[5:4]   OUT6_DIS_STATE              0                  0x0              
 * 0x0131[7:6]   OUT6_CMOS_DRV               0                  0x0              
 * 0x0132[3:0]   OUT6_CM                     11                 0xB              
 * 0x0132[6:4]   OUT6_AMPL                   3                  0x3              
 * 0x0133[2:0]   OUT6_MUX_SEL                0                  0x0              
 * 0x0133[5:4]   OUT6_VDD_SEL                2                  0x2              
 * 0x0133[3]     OUT6_VDD_SEL_EN             1                  0x1              
 * 0x0133[7:6]   OUT6_INV                    0                  0x0              
 * 0x0134[2:0]   OUT6_DIS_SRC                0                  0x0              
 * 0x013A[0]     OUT7_PDN                    1                  0x1              
 * 0x013A[1]     OUT7_OE                     0                  0x0              
 * 0x013A[2]     OUT7_RDIV_FORCE2            0                  0x0              
 * 0x013B[2:0]   OUT7_FORMAT                 1                  0x1              
 * 0x013B[3]     OUT7_SYNC_EN                1                  0x1              
 * 0x013B[5:4]   OUT7_DIS_STATE              0                  0x0              
 * 0x013B[7:6]   OUT7_CMOS_DRV               0                  0x0              
 * 0x013C[3:0]   OUT7_CM                     11                 0xB              
 * 0x013C[6:4]   OUT7_AMPL                   3                  0x3              
 * 0x013D[2:0]   OUT7_MUX_SEL                0                  0x0              
 * 0x013D[5:4]   OUT7_VDD_SEL                2                  0x2              
 * 0x013D[3]     OUT7_VDD_SEL_EN             1                  0x1              
 * 0x013D[7:6]   OUT7_INV                    0                  0x0              
 * 0x013E[2:0]   OUT7_DIS_SRC                0                  0x0              
 * 0x013F[11:0]  OUTX_ALWAYS_ON              0                  0x000            
 * 0x0141[0]     OUT_DIS_MSK_PLLA            0                  0x0              
 * 0x0141[1]     OUT_DIS_MSK_PLLB            0                  0x0              
 * 0x0141[2]     OUT_DIS_MSK_PLLC            0                  0x0              
 * 0x0141[3]     OUT_DIS_MSK_PLLD            0                  0x0              
 * 0x0141[5]     OUT_DIS_LOL_MSK             0                  0x0              
 * 0x0141[6]     OUT_DIS_LOSXAXB_MSK         1                  0x1              
 * 0x0141[7]     OUT_DIS_MSK_LOS_PFD         0                  0x0              
 * 0x0142[0]     OUT_DIS_MSK_LOL_PLLA        1                  0x1              
 * 0x0142[1]     OUT_DIS_MSK_LOL_PLLB        1                  0x1              
 * 0x0142[2]     OUT_DIS_MSK_LOL_PLLC        1                  0x1              
 * 0x0142[3]     OUT_DIS_MSK_LOL_PLLD        1                  0x1              
 * 0x0142[4]     OUT_DIS_MSK_HOLD_PLLA       1                  0x1              
 * 0x0142[5]     OUT_DIS_MSK_HOLD_PLLB       1                  0x1              
 * 0x0142[6]     OUT_DIS_MSK_HOLD_PLLC       1                  0x1              
 * 0x0142[7]     OUT_DIS_MSK_HOLD_PLLD       1                  0x1              
 * 0x0206[1:0]   PXAXB                       0                  0x0              
 * 0x0208[47:0]  P0_NUM                      63                 0x00000000003F   
 * 0x020E[31:0]  P0_DEN                      1                  0x00000001       
 * 0x0212[47:0]  P1_NUM                      0                  0x000000000000   
 * 0x0218[31:0]  P1_DEN                      0                  0x00000000       
 * 0x021C[47:0]  P2_NUM                      0                  0x000000000000   
 * 0x0222[31:0]  P2_DEN                      0                  0x00000000       
 * 0x0226[47:0]  P3_NUM                      0                  0x000000000000   
 * 0x022C[31:0]  P3_DEN                      0                  0x00000000       
 * 0x0231[3:0]   P0_FRACN_MODE               11                 0xB              
 * 0x0231[4]     P0_FRACN_EN                 0                  0x0              
 * 0x0232[3:0]   P1_FRACN_MODE               11                 0xB              
 * 0x0232[4]     P1_FRACN_EN                 0                  0x0              
 * 0x0233[3:0]   P2_FRACN_MODE               11                 0xB              
 * 0x0233[4]     P2_FRACN_EN                 0                  0x0              
 * 0x0234[3:0]   P3_FRACN_MODE               11                 0xB              
 * 0x0234[4]     P3_FRACN_EN                 0                  0x0              
 * 0x0235[43:0]  MXAXB_NUM                   633507676160       0x09380000000    
 * 0x023B[31:0]  MXAXB_DEN                   2147483648         0x80000000       
 * 0x024A[23:0]  R0_REG                      4687499            0x47868B         
 * 0x0250[23:0]  R1_REG                      0                  0x000000         
 * 0x0253[23:0]  R2_REG                      2                  0x000002         
 * 0x0256[23:0]  R3_REG                      0                  0x000000         
 * 0x025C[23:0]  R4_REG                      2                  0x000002         
 * 0x025F[23:0]  R5_REG                      0                  0x000000         
 * 0x0262[23:0]  R6_REG                      0                  0x000000         
 * 0x0268[23:0]  R7_REG                      0                  0x000000         
 * 0x026B[7:0]   DESIGN_ID0                  122                0x7A             
 * 0x026C[7:0]   DESIGN_ID1                  117                0x75             
 * 0x026D[7:0]   DESIGN_ID2                  98                 0x62             
 * 0x026E[7:0]   DESIGN_ID3                  112                0x70             
 * 0x026F[7:0]   DESIGN_ID4                  109                0x6D             
 * 0x0270[7:0]   DESIGN_ID5                  0                  0x00             
 * 0x0271[7:0]   DESIGN_ID6                  0                  0x00             
 * 0x0272[7:0]   DESIGN_ID7                  0                  0x00             
 * 0x028A[4:0]   OOF0_TRG_THR_EXT            0                  0x00             
 * 0x028B[4:0]   OOF1_TRG_THR_EXT            0                  0x00             
 * 0x028C[4:0]   OOF2_TRG_THR_EXT            0                  0x00             
 * 0x028D[4:0]   OOF3_TRG_THR_EXT            0                  0x00             
 * 0x028E[4:0]   OOF0_CLR_THR_EXT            0                  0x00             
 * 0x028F[4:0]   OOF1_CLR_THR_EXT            0                  0x00             
 * 0x0290[4:0]   OOF2_CLR_THR_EXT            0                  0x00             
 * 0x0291[4:0]   OOF3_CLR_THR_EXT            0                  0x00             
 * 0x0294[3:0]   FASTLOCK_EXTEND_SCL_PLLA    8                  0x8              
 * 0x0294[7:4]   FASTLOCK_EXTEND_SCL_PLLB    8                  0x8              
 * 0x0295[3:0]   FASTLOCK_EXTEND_SCL_PLLC    8                  0x8              
 * 0x0295[7:4]   FASTLOCK_EXTEND_SCL_PLLD    8                  0x8              
 * 0x0296[0]     LOL_SLW_VALWIN_SELX_PLLA    1                  0x1              
 * 0x0296[1]     LOL_SLW_VALWIN_SELX_PLLB    0                  0x0              
 * 0x0296[2]     LOL_SLW_VALWIN_SELX_PLLC    0                  0x0              
 * 0x0296[3]     LOL_SLW_VALWIN_SELX_PLLD    0                  0x0              
 * 0x0297[0]     FASTLOCK_DLY_ONSW_EN_PLLA   1                  0x1              
 * 0x0297[1]     FASTLOCK_DLY_ONSW_EN_PLLB   0                  0x0              
 * 0x0297[2]     FASTLOCK_DLY_ONSW_EN_PLLC   0                  0x0              
 * 0x0297[3]     FASTLOCK_DLY_ONSW_EN_PLLD   0                  0x0              
 * 0x0299[0]     FASTLOCK_DLY_ONLOL_EN_PLLA  1                  0x1              
 * 0x0299[1]     FASTLOCK_DLY_ONLOL_EN_PLLB  0                  0x0              
 * 0x0299[2]     FASTLOCK_DLY_ONLOL_EN_PLLC  0                  0x0              
 * 0x0299[3]     FASTLOCK_DLY_ONLOL_EN_PLLD  0                  0x0              
 * 0x029A[19:0]  FASTLOCK_DLY_ONLOL_PLLA     506                0x001FA          
 * 0x029D[19:0]  FASTLOCK_DLY_ONLOL_PLLB     0                  0x00000          
 * 0x02A0[19:0]  FASTLOCK_DLY_ONLOL_PLLC     0                  0x00000          
 * 0x02A3[19:0]  FASTLOCK_DLY_ONLOL_PLLD     0                  0x00000          
 * 0x02A6[19:0]  FASTLOCK_DLY_ONSW_PLLA      1228               0x004CC          
 * 0x02A9[19:0]  FASTLOCK_DLY_ONSW_PLLB      0                  0x00000          
 * 0x02AC[19:0]  FASTLOCK_DLY_ONSW_PLLC      0                  0x00000          
 * 0x02AF[19:0]  FASTLOCK_DLY_ONSW_PLLD      0                  0x00000          
 * 0x02B7[1:0]   LOL_NOSIG_TIME_PLLA         3                  0x3              
 * 0x02B7[3:2]   LOL_NOSIG_TIME_PLLB         3                  0x3              
 * 0x02B7[5:4]   LOL_NOSIG_TIME_PLLC         3                  0x3              
 * 0x02B7[7:6]   LOL_NOSIG_TIME_PLLD         3                  0x3              
 * 0x0302[43:0]  N0_NUM                      61865984000        0x00E67800000    
 * 0x0308[31:0]  N0_DEN                      3274702848         0xC3300000       
 * 0x030C[0]     N0_UPDATE                   0                  0x0              
 * 0x030D[43:0]  N1_NUM                      63350767616        0x00EC0000000    
 * 0x0313[31:0]  N1_DEN                      4194304000         0xFA000000       
 * 0x0317[0]     N1_UPDATE                   0                  0x0              
 * 0x0318[43:0]  N2_NUM                      0                  0x00000000000    
 * 0x031E[31:0]  N2_DEN                      0                  0x00000000       
 * 0x0322[0]     N2_UPDATE                   0                  0x0              
 * 0x0323[43:0]  N3_NUM                      0                  0x00000000000    
 * 0x0329[31:0]  N3_DEN                      0                  0x00000000       
 * 0x032D[0]     N3_UPDATE                   0                  0x0              
 * 0x0338[1]     N_UPDATE                    0                  0x0              
 * 0x033B[43:0]  N0_FSTEPW                   0                  0x00000000000    
 * 0x0341[43:0]  N1_FSTEPW                   0                  0x00000000000    
 * 0x0347[43:0]  N2_FSTEPW                   0                  0x00000000000    
 * 0x034D[43:0]  N3_FSTEPW                   0                  0x00000000000    
 * 0x0408[5:0]   BW0_PLLA                    15                 0x0F             
 * 0x0409[5:0]   BW1_PLLA                    33                 0x21             
 * 0x040A[5:0]   BW2_PLLA                    9                  0x09             
 * 0x040B[5:0]   BW3_PLLA                    8                  0x08             
 * 0x040C[5:0]   BW4_PLLA                    63                 0x3F             
 * 0x040D[5:0]   BW5_PLLA                    63                 0x3F             
 * 0x040E[5:0]   FASTLOCK_BW0_PLLA           15                 0x0F             
 * 0x040F[5:0]   FASTLOCK_BW1_PLLA           35                 0x23             
 * 0x0410[5:0]   FASTLOCK_BW2_PLLA           9                  0x09             
 * 0x0411[5:0]   FASTLOCK_BW3_PLLA           8                  0x08             
 * 0x0412[5:0]   FASTLOCK_BW4_PLLA           63                 0x3F             
 * 0x0413[5:0]   FASTLOCK_BW5_PLLA           63                 0x3F             
 * 0x0415[55:0]  M_NUM_PLLA                  811748818944       0x0000BD00000000 
 * 0x041C[31:0]  M_DEN_PLLA                  2147483648         0x80000000       
 * 0x0421[3:0]   M_FRAC_MODE_PLLA            11                 0xB              
 * 0x0421[4]     M_FRAC_EN_PLLA              0                  0x0              
 * 0x0422[0]     M_FSTEP_MSK_PLLA            1                  0x1              
 * 0x0422[1]     M_FSTEPW_DEN_PLLA           0                  0x0              
 * 0x0423[55:0]  M_FSTEPW_PLLA               0                  0x00000000000000 
 * 0x042A[2:0]   IN_SEL_PLLA                 0                  0x0              
 * 0x042B[0]     FASTLOCK_AUTO_EN_PLLA       1                  0x1              
 * 0x042B[1]     FASTLOCK_MAN_PLLA           0                  0x0              
 * 0x042C[0]     HOLD_EN_PLLA                1                  0x1              
 * 0x042C[3]     HOLD_RAMP_BYP_PLLA          0                  0x0              
 * 0x042C[4]     HOLDEXIT_BW_SEL1_PLLA       0                  0x0              
 * 0x042C[7:5]   RAMP_STEP_INTERVAL_PLLA     4                  0x4              
 * 0x042D[1]     HOLD_RAMPBYP_NOHIST_PLLA    1                  0x1              
 * 0x042E[4:0]   HOLD_HIST_LEN_PLLA          25                 0x19             
 * 0x042F[4:0]   HOLD_HIST_DELAY_PLLA        25                 0x19             
 * 0x0431[4:0]   HOLD_REF_COUNT_FRC_PLLA     0                  0x00             
 * 0x0432[23:0]  HOLD_15M_CYC_COUNT_PLLA     841                0x000349         
 * 0x0435[0]     FORCE_HOLD_PLLA             0                  0x0              
 * 0x0436[1:0]   CLK_SWITCH_MODE_PLLA        0                  0x0              
 * 0x0436[2]     HSW_EN_PLLA                 1                  0x1              
 * 0x0437[3:0]   IN_LOS_MSK_PLLA             0                  0x0              
 * 0x0437[7:4]   IN_OOF_MSK_PLLA             0                  0x0              
 * 0x0438[2:0]   IN0_PRIORITY_PLLA           0                  0x0              
 * 0x0438[6:4]   IN1_PRIORITY_PLLA           0                  0x0              
 * 0x0439[2:0]   IN2_PRIORITY_PLLA           0                  0x0              
 * 0x0439[6:4]   IN3_PRIORITY_PLLA           0                  0x0              
 * 0x043A[1:0]   HSW_MODE_PLLA               2                  0x2              
 * 0x043A[3:2]   HSW_PHMEAS_CTRL_PLLA        0                  0x0              
 * 0x043B[9:0]   HSW_PHMEAS_THR_PLLA         3                  0x003            
 * 0x043D[4:0]   HSW_COARSE_PM_LEN_PLLA      14                 0x0E             
 * 0x043E[4:0]   HSW_COARSE_PM_DLY_PLLA      6                  0x06             
 * 0x0442[17:0]  FINE_ADJ_OVR_PLLA           0                  0x00000          
 * 0x0445[1]     FORCE_FINE_ADJ_PLLA         0                  0x0              
 * 0x0489[12:0]  PFD_EN_DELAY_PLLA           13                 0x000D           
 * 0x049B[1]     INIT_LP_CLOSE_HO_PLLA       0                  0x0              
 * 0x049B[2]     HO_SKIP_PHASE_PLLA          0                  0x0              
 * 0x049B[4]     HOLD_PRESERVE_HIST_PLLA     1                  0x1              
 * 0x049B[5]     HOLD_FRZ_WITH_INTONLY_PLLA  1                  0x1              
 * 0x049B[6]     HOLDEXIT_BW_SEL0_PLLA       1                  0x1              
 * 0x049B[7]     HOLDEXIT_STD_BO_PLLA        1                  0x1              
 * 0x049D[5:0]   BW0_HO_PLLA                 15                 0x0F             
 * 0x049E[5:0]   BW1_HO_PLLA                 35                 0x23             
 * 0x049F[5:0]   BW2_HO_PLLA                 9                  0x09             
 * 0x04A0[5:0]   BW3_HO_PLLA                 8                  0x08             
 * 0x04A1[5:0]   BW4_HO_PLLA                 63                 0x3F             
 * 0x04A2[5:0]   BW5_HO_PLLA                 63                 0x3F             
 * 0x04A6[2:0]   RAMP_STEP_SIZE_PLLA         3                  0x3              
 * 0x04A6[3]     RAMP_SWITCH_EN_PLLA         0                  0x0              
 * 0x0508[5:0]   BW0_PLLB                    0                  0x00             
 * 0x0509[5:0]   BW1_PLLB                    0                  0x00             
 * 0x050A[5:0]   BW2_PLLB                    0                  0x00             
 * 0x050B[5:0]   BW3_PLLB                    0                  0x00             
 * 0x050C[5:0]   BW4_PLLB                    0                  0x00             
 * 0x050D[5:0]   BW5_PLLB                    0                  0x00             
 * 0x050E[5:0]   FASTLOCK_BW0_PLLB           0                  0x00             
 * 0x050F[5:0]   FASTLOCK_BW1_PLLB           0                  0x00             
 * 0x0510[5:0]   FASTLOCK_BW2_PLLB           0                  0x00             
 * 0x0511[5:0]   FASTLOCK_BW3_PLLB           0                  0x00             
 * 0x0512[5:0]   FASTLOCK_BW4_PLLB           0                  0x00             
 * 0x0513[5:0]   FASTLOCK_BW5_PLLB           0                  0x00             
 * 0x0515[55:0]  M_NUM_PLLB                  0                  0x00000000000000 
 * 0x051C[31:0]  M_DEN_PLLB                  0                  0x00000000       
 * 0x0521[3:0]   M_FRAC_MODE_PLLB            11                 0xB              
 * 0x0521[4]     M_FRAC_EN_PLLB              0                  0x0              
 * 0x0522[0]     M_FSTEP_MSK_PLLB            1                  0x1              
 * 0x0522[1]     M_FSTEPW_DEN_PLLB           0                  0x0              
 * 0x0523[55:0]  M_FSTEPW_PLLB               0                  0x00000000000000 
 * 0x052A[0]     IN_SEL_REGCTRL_PLLB         1                  0x1              
 * 0x052A[3:1]   IN_SEL_PLLB                 1                  0x1              
 * 0x052B[0]     FASTLOCK_AUTO_EN_PLLB       1                  0x1              
 * 0x052B[1]     FASTLOCK_MAN_PLLB           0                  0x0              
 * 0x052C[0]     HOLD_EN_PLLB                1                  0x1              
 * 0x052C[3]     HOLD_RAMP_BYP_PLLB          1                  0x1              
 * 0x052C[4]     HOLDEXIT_BW_SEL1_PLLB       0                  0x0              
 * 0x052C[7:5]   RAMP_STEP_INTERVAL_PLLB     0                  0x0              
 * 0x052D[1]     HOLD_RAMPBYP_NOHIST_PLLB    1                  0x1              
 * 0x052E[4:0]   HOLD_HIST_LEN_PLLB          0                  0x00             
 * 0x052F[4:0]   HOLD_HIST_DELAY_PLLB        0                  0x00             
 * 0x0531[4:0]   HOLD_REF_COUNT_FRC_PLLB     0                  0x00             
 * 0x0532[23:0]  HOLD_15M_CYC_COUNT_PLLB     1024               0x000400         
 * 0x0535[0]     FORCE_HOLD_PLLB             1                  0x1              
 * 0x0536[1:0]   CLK_SWITCH_MODE_PLLB        0                  0x0              
 * 0x0536[2]     HSW_EN_PLLB                 1                  0x1              
 * 0x0537[3:0]   IN_LOS_MSK_PLLB             0                  0x0              
 * 0x0537[7:4]   IN_OOF_MSK_PLLB             0                  0x0              
 * 0x0538[2:0]   IN0_PRIORITY_PLLB           0                  0x0              
 * 0x0538[6:4]   IN1_PRIORITY_PLLB           0                  0x0              
 * 0x0539[2:0]   IN2_PRIORITY_PLLB           0                  0x0              
 * 0x0539[6:4]   IN3_PRIORITY_PLLB           0                  0x0              
 * 0x053D[4:0]   HSW_COARSE_PM_LEN_PLLB      10                 0x0A             
 * 0x053E[4:0]   HSW_COARSE_PM_DLY_PLLB      6                  0x06             
 * 0x0542[17:0]  FINE_ADJ_OVR_PLLB           0                  0x00000          
 * 0x0545[1]     FORCE_FINE_ADJ_PLLB         0                  0x0              
 * 0x0589[12:0]  PFD_EN_DELAY_PLLB           12                 0x000C           
 * 0x059B[1]     INIT_LP_CLOSE_HO_PLLB       0                  0x0              
 * 0x059B[2]     HO_SKIP_PHASE_PLLB          0                  0x0              
 * 0x059B[4]     HOLD_PRESERVE_HIST_PLLB     1                  0x1              
 * 0x059B[5]     HOLD_FRZ_WITH_INTONLY_PLLB  0                  0x0              
 * 0x059B[6]     HOLDEXIT_BW_SEL0_PLLB       0                  0x0              
 * 0x059B[7]     HOLDEXIT_STD_BO_PLLB        0                  0x0              
 * 0x059D[5:0]   HOLDEXIT_BW0_PLLB           0                  0x00             
 * 0x059E[5:0]   HOLDEXIT_BW1_PLLB           0                  0x00             
 * 0x059F[5:0]   HOLDEXIT_BW2_PLLB           0                  0x00             
 * 0x05A0[5:0]   HOLDEXIT_BW3_PLLB           0                  0x00             
 * 0x05A1[5:0]   HOLDEXIT_BW4_PLLB           0                  0x00             
 * 0x05A2[5:0]   HOLDEXIT_BW5_PLLB           0                  0x00             
 * 0x05A6[2:0]   RAMP_STEP_SIZE_PLLB         0                  0x0              
 * 0x05A6[3]     RAMP_SWITCH_EN_PLLB         0                  0x0              
 * 0x0602[4]     ADD_DIV256_PLLC             0                  0x0              
 * 0x0608[5:0]   BW0_PLLC                    0                  0x00             
 * 0x0609[5:0]   BW1_PLLC                    0                  0x00             
 * 0x060A[5:0]   BW2_PLLC                    0                  0x00             
 * 0x060B[5:0]   BW3_PLLC                    0                  0x00             
 * 0x060C[5:0]   BW4_PLLC                    0                  0x00             
 * 0x060D[5:0]   BW5_PLLC                    0                  0x00             
 * 0x060E[5:0]   FASTLOCK_BW0_PLLC           0                  0x00             
 * 0x060F[5:0]   FASTLOCK_BW1_PLLC           0                  0x00             
 * 0x0610[5:0]   FASTLOCK_BW2_PLLC           0                  0x00             
 * 0x0611[5:0]   FASTLOCK_BW3_PLLC           0                  0x00             
 * 0x0612[5:0]   FASTLOCK_BW4_PLLC           0                  0x00             
 * 0x0613[5:0]   FASTLOCK_BW5_PLLC           0                  0x00             
 * 0x0615[55:0]  M_NUM_PLLC                  0                  0x00000000000000 
 * 0x061C[31:0]  M_DEN_PLLC                  0                  0x00000000       
 * 0x0621[3:0]   M_FRAC_MODE_PLLC            11                 0xB              
 * 0x0621[4]     M_FRAC_EN_PLLC              0                  0x0              
 * 0x0622[0]     M_FSTEP_MSK_PLLC            1                  0x1              
 * 0x0622[1]     M_FSTEPW_DEN_PLLC           0                  0x0              
 * 0x0623[55:0]  M_FSTEPW_PLLC               0                  0x00000000000000 
 * 0x062A[2:0]   IN_SEL_PLLC                 0                  0x0              
 * 0x062B[0]     FASTLOCK_AUTO_EN_PLLC       1                  0x1              
 * 0x062B[1]     FASTLOCK_MAN_PLLC           0                  0x0              
 * 0x062C[0]     HOLD_EN_PLLC                1                  0x1              
 * 0x062C[3]     HOLD_RAMP_BYP_PLLC          1                  0x1              
 * 0x062C[4]     HOLDEXIT_BW_SEL1_PLLC       0                  0x0              
 * 0x062C[7:5]   RAMP_STEP_INTERVAL_PLLC     0                  0x0              
 * 0x062D[1]     HOLD_RAMPBYP_NOHIST_PLLC    1                  0x1              
 * 0x062E[4:0]   HOLD_HIST_LEN_PLLC          0                  0x00             
 * 0x062F[4:0]   HOLD_HIST_DELAY_PLLC        0                  0x00             
 * 0x0631[4:0]   HOLD_REF_COUNT_FRC_PLLC     0                  0x00             
 * 0x0632[23:0]  HOLD_15M_CYC_COUNT_PLLC     1024               0x000400         
 * 0x0636[1:0]   CLK_SWITCH_MODE_PLLC        2                  0x2              
 * 0x0636[2]     HSW_EN_PLLC                 1                  0x1              
 * 0x0637[3:0]   IN_LOS_MSK_PLLC             0                  0x0              
 * 0x0637[7:4]   IN_OOF_MSK_PLLC             0                  0x0              
 * 0x0638[2:0]   IN0_PRIORITY_PLLC           0                  0x0              
 * 0x0638[6:4]   IN1_PRIORITY_PLLC           0                  0x0              
 * 0x0639[2:0]   IN2_PRIORITY_PLLC           0                  0x0              
 * 0x0639[6:4]   IN3_PRIORITY_PLLC           0                  0x0              
 * 0x063D[4:0]   HSW_COARSE_PM_LEN_PLLC      10                 0x0A             
 * 0x063E[4:0]   HSW_COARSE_PM_DLY_PLLC      6                  0x06             
 * 0x0689[12:0]  PFD_EN_DELAY_PLLC           12                 0x000C           
 * 0x069B[1]     INIT_LP_CLOSE_HO_PLLC       0                  0x0              
 * 0x069B[2]     HO_SKIP_PHASE_PLLC          0                  0x0              
 * 0x069B[4]     HOLD_PRESERVE_HIST_PLLC     1                  0x1              
 * 0x069B[5]     HOLD_FRZ_WITH_INTONLY_PLLC  0                  0x0              
 * 0x069B[6]     HOLDEXIT_BW_SEL0_PLLC       0                  0x0              
 * 0x069B[7]     HOLDEXIT_STD_BO_PLLC        0                  0x0              
 * 0x069D[5:0]   HOLDEXIT_BW0_PLLC           0                  0x00             
 * 0x069E[5:0]   HOLDEXIT_BW1_PLLC           0                  0x00             
 * 0x069F[5:0]   HOLDEXIT_BW2_PLLC           0                  0x00             
 * 0x06A0[5:0]   HOLDEXIT_BW3_PLLC           0                  0x00             
 * 0x06A1[5:0]   HOLDEXIT_BW4_PLLC           0                  0x00             
 * 0x06A2[5:0]   HOLDEXIT_BW5_PLLC           0                  0x00             
 * 0x06A6[2:0]   RAMP_STEP_SIZE_PLLC         0                  0x0              
 * 0x06A6[3]     RAMP_SWITCH_EN_PLLC         0                  0x0              
 * 0x0702[4]     ADD_DIV256_PLLD             0                  0x0              
 * 0x0709[5:0]   BW0_PLLD                    0                  0x00             
 * 0x070A[5:0]   BW1_PLLD                    0                  0x00             
 * 0x070B[5:0]   BW2_PLLD                    0                  0x00             
 * 0x070C[5:0]   BW3_PLLD                    0                  0x00             
 * 0x070D[5:0]   BW4_PLLD                    0                  0x00             
 * 0x070E[5:0]   BW5_PLLD                    0                  0x00             
 * 0x070F[5:0]   FASTLOCK_BW0_PLLD           0                  0x00             
 * 0x0710[5:0]   FASTLOCK_BW1_PLLD           0                  0x00             
 * 0x0711[5:0]   FASTLOCK_BW2_PLLD           0                  0x00             
 * 0x0712[5:0]   FASTLOCK_BW3_PLLD           0                  0x00             
 * 0x0713[5:0]   FASTLOCK_BW4_PLLD           0                  0x00             
 * 0x0714[5:0]   FASTLOCK_BW5_PLLD           0                  0x00             
 * 0x0716[55:0]  M_NUM_PLLD                  0                  0x00000000000000 
 * 0x071D[31:0]  M_DEN_PLLD                  0                  0x00000000       
 * 0x0722[3:0]   M_FRAC_MODE_PLLD            11                 0xB              
 * 0x0722[4]     M_FRAC_EN_PLLD              0                  0x0              
 * 0x0723[0]     M_FSTEP_MSK_PLLD            1                  0x1              
 * 0x0723[1]     M_FSTEPW_DEN_PLLD           0                  0x0              
 * 0x0724[55:0]  M_FSTEPW_PLLD               0                  0x00000000000000 
 * 0x072B[2:0]   IN_SEL_PLLD                 0                  0x0              
 * 0x072C[0]     FASTLOCK_AUTO_EN_PLLD       1                  0x1              
 * 0x072C[1]     FASTLOCK_MAN_PLLD           0                  0x0              
 * 0x072D[0]     HOLD_EN_PLLD                1                  0x1              
 * 0x072D[3]     HOLD_RAMP_BYP_PLLD          1                  0x1              
 * 0x072D[4]     HOLDEXIT_BW_SEL1_PLLD       0                  0x0              
 * 0x072D[7:5]   RAMP_STEP_INTERVAL_PLLD     0                  0x0              
 * 0x072E[1]     HOLD_RAMPBYP_NOHIST_PLLD    1                  0x1              
 * 0x072F[4:0]   HOLD_HIST_LEN_PLLD          0                  0x00             
 * 0x0730[4:0]   HOLD_HIST_DELAY_PLLD        0                  0x00             
 * 0x0732[4:0]   HOLD_REF_COUNT_FRC_PLLD     0                  0x00             
 * 0x0733[23:0]  HOLD_15M_CYC_COUNT_PLLD     1024               0x000400         
 * 0x0737[1:0]   CLK_SWITCH_MODE_PLLD        2                  0x2              
 * 0x0737[2]     HSW_EN_PLLD                 1                  0x1              
 * 0x0738[3:0]   IN_LOS_MSK_PLLD             0                  0x0              
 * 0x0738[7:4]   IN_OOF_MSK_PLLD             0                  0x0              
 * 0x0739[2:0]   IN0_PRIORITY_PLLD           0                  0x0              
 * 0x0739[6:4]   IN1_PRIORITY_PLLD           0                  0x0              
 * 0x073A[2:0]   IN2_PRIORITY_PLLD           0                  0x0              
 * 0x073A[6:4]   IN3_PRIORITY_PLLD           0                  0x0              
 * 0x073E[4:0]   HSW_COARSE_PM_LEN_PLLD      10                 0x0A             
 * 0x073F[4:0]   HSW_COARSE_PM_DLY_PLLD      6                  0x06             
 * 0x0789[12:0]  PFD_EN_DELAY_PLLD           12                 0x000C           
 * 0x079B[1]     INIT_LP_CLOSE_HO_PLLD       0                  0x0              
 * 0x079B[2]     HO_SKIP_PHASE_PLLD          0                  0x0              
 * 0x079B[4]     HOLD_PRESERVE_HIST_PLLD     1                  0x1              
 * 0x079B[5]     HOLD_FRZ_WITH_INTONLY_PLLD  0                  0x0              
 * 0x079B[6]     HOLDEXIT_BW_SEL0_PLLD       0                  0x0              
 * 0x079B[7]     HOLDEXIT_STD_BO_PLLD        0                  0x0              
 * 0x079D[5:0]   HOLDEXIT_BW0_PLLD           0                  0x00             
 * 0x079E[5:0]   HOLDEXIT_BW1_PLLD           0                  0x00             
 * 0x079F[5:0]   HOLDEXIT_BW2_PLLD           0                  0x00             
 * 0x07A0[5:0]   HOLDEXIT_BW3_PLLD           0                  0x00             
 * 0x07A1[5:0]   HOLDEXIT_BW4_PLLD           0                  0x00             
 * 0x07A2[5:0]   HOLDEXIT_BW5_PLLD           0                  0x00             
 * 0x07A6[2:0]   RAMP_STEP_SIZE_PLLD         0                  0x0              
 * 0x07A6[3]     RAMP_SWITCH_EN_PLLD         0                  0x0              
 * 0x0802[15:0]  FIXREGSA0                   1077               0x0435           
 * 0x0804[7:0]   FIXREGSD0                   0                  0x00             
 * 0x0805[15:0]  FIXREGSA1                   1093               0x0445           
 * 0x0807[7:0]   FIXREGSD1                   0                  0x00             
 * 0x0808[15:0]  FIXREGSA2                   1090               0x0442           
 * 0x080A[7:0]   FIXREGSD2                   0                  0x00             
 * 0x080B[15:0]  FIXREGSA3                   1091               0x0443           
 * 0x080D[7:0]   FIXREGSD3                   0                  0x00             
 * 0x080E[15:0]  FIXREGSA4                   1092               0x0444           
 * 0x0810[7:0]   FIXREGSD4                   0                  0x00             
 * 0x0811[15:0]  FIXREGSA5                   1333               0x0535           
 * 0x0813[7:0]   FIXREGSD5                   1                  0x01             
 * 0x0814[15:0]  FIXREGSA6                   1349               0x0545           
 * 0x0816[7:0]   FIXREGSD6                   0                  0x00             
 * 0x0817[15:0]  FIXREGSA7                   1346               0x0542           
 * 0x0819[7:0]   FIXREGSD7                   0                  0x00             
 * 0x081A[15:0]  FIXREGSA8                   1347               0x0543           
 * 0x081C[7:0]   FIXREGSD8                   0                  0x00             
 * 0x081D[15:0]  FIXREGSA9                   1348               0x0544           
 * 0x081F[7:0]   FIXREGSD9                   0                  0x00             
 * 0x0820[15:0]  FIXREGSA10                  0                  0x0000           
 * 0x0822[7:0]   FIXREGSD10                  0                  0x00             
 * 0x0823[15:0]  FIXREGSA11                  0                  0x0000           
 * 0x0825[7:0]   FIXREGSD11                  0                  0x00             
 * 0x0826[15:0]  FIXREGSA12                  0                  0x0000           
 * 0x0828[7:0]   FIXREGSD12                  0                  0x00             
 * 0x0829[15:0]  FIXREGSA13                  0                  0x0000           
 * 0x082B[7:0]   FIXREGSD13                  0                  0x00             
 * 0x082C[15:0]  FIXREGSA14                  0                  0x0000           
 * 0x082E[7:0]   FIXREGSD14                  0                  0x00             
 * 0x082F[15:0]  FIXREGSA15                  0                  0x0000           
 * 0x0831[7:0]   FIXREGSD15                  0                  0x00             
 * 0x0832[15:0]  FIXREGSA16                  0                  0x0000           
 * 0x0834[7:0]   FIXREGSD16                  0                  0x00             
 * 0x0835[15:0]  FIXREGSA17                  0                  0x0000           
 * 0x0837[7:0]   FIXREGSD17                  0                  0x00             
 * 0x0838[15:0]  FIXREGSA18                  0                  0x0000           
 * 0x083A[7:0]   FIXREGSD18                  0                  0x00             
 * 0x083B[15:0]  FIXREGSA19                  0                  0x0000           
 * 0x083D[7:0]   FIXREGSD19                  0                  0x00             
 * 0x083E[15:0]  FIXREGSA20                  0                  0x0000           
 * 0x0840[7:0]   FIXREGSD20                  0                  0x00             
 * 0x0841[15:0]  FIXREGSA21                  0                  0x0000           
 * 0x0843[7:0]   FIXREGSD21                  0                  0x00             
 * 0x0844[15:0]  FIXREGSA22                  0                  0x0000           
 * 0x0846[7:0]   FIXREGSD22                  0                  0x00             
 * 0x0847[15:0]  FIXREGSA23                  0                  0x0000           
 * 0x0849[7:0]   FIXREGSD23                  0                  0x00             
 * 0x084A[15:0]  FIXREGSA24                  0                  0x0000           
 * 0x084C[7:0]   FIXREGSD24                  0                  0x00             
 * 0x084D[15:0]  FIXREGSA25                  0                  0x0000           
 * 0x084F[7:0]   FIXREGSD25                  0                  0x00             
 * 0x0850[15:0]  FIXREGSA26                  0                  0x0000           
 * 0x0852[7:0]   FIXREGSD26                  0                  0x00             
 * 0x0853[15:0]  FIXREGSA27                  0                  0x0000           
 * 0x0855[7:0]   FIXREGSD27                  0                  0x00             
 * 0x0856[15:0]  FIXREGSA28                  0                  0x0000           
 * 0x0858[7:0]   FIXREGSD28                  0                  0x00             
 * 0x0859[15:0]  FIXREGSA29                  0                  0x0000           
 * 0x085B[7:0]   FIXREGSD29                  0                  0x00             
 * 0x085C[15:0]  FIXREGSA30                  0                  0x0000           
 * 0x085E[7:0]   FIXREGSD30                  0                  0x00             
 * 0x085F[15:0]  FIXREGSA31                  0                  0x0000           
 * 0x0861[7:0]   FIXREGSD31                  0                  0x00             
 * 0x090E[0]     XAXB_EXTCLK_EN              0                  0x0              
 * 0x0943[0]     IO_VDD_SEL                  1                  0x1              
 * 0x0949[3:0]   IN_EN                       1                  0x1              
 * 0x0949[7:4]   IN_PULSED_CMOS_EN           0                  0x0              
 * 0x094A[3:0]   INX_TO_PFD_EN               1                  0x1              
 * 0x094E[11:0]  REFCLK_HYS_SEL              585                0x249            
 * 0x095E[0]     MXAXB_INTEGER               0                  0x0              
 * 0x0A03[4:0]   N_CLK_TO_OUTX_EN            3                  0x03             
 * 0x0A04[4:0]   N_PIBYP                     0                  0x00             
 * 0x0A05[4:0]   N_PDNB                      3                  0x03             
 * 0x0B44[3:0]   PDIV_FRACN_CLK_DIS          15                 0xF              
 * 0x0B44[4]     FRACN_CLK_DIS_PLLA          1                  0x1              
 * 0x0B44[5]     FRACN_CLK_DIS_PLLB          0                  0x0              
 * 0x0B44[6]     FRACN_CLK_DIS_PLLC          0                  0x0              
 * 0x0B44[7]     FRACN_CLK_DIS_PLLD          0                  0x0              
 * 0x0B45[0]     CLK_DIS_PLLA                0                  0x0              
 * 0x0B45[1]     CLK_DIS_PLLB                0                  0x0              
 * 0x0B45[2]     CLK_DIS_PLLC                1                  0x1              
 * 0x0B45[3]     CLK_DIS_PLLD                1                  0x1              
 * 0x0B46[3:0]   LOS_CLK_DIS                 0                  0x0              
 * 0x0B47[4:0]   OOF_CLK_DIS                 14                 0x0E             
 * 0x0B48[4:0]   OOF_DIV_CLK_DIS             14                 0x0E             
 * 0x0B4A[4:0]   N_CLK_DIS                   12                 0x0C             
 * 0x0B57[11:0]  VCO_RESET_CALCODE           270                0x10E
 * 
 *
 */

#endif
