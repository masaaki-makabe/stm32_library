#ifndef EPROM_H
#define EPROM_H

#include "mbed/mbed.h"
#include <string>

#define EEPROM_Addr        0xA0
#define EEPROM_Freq        100000

#define EEPROM_NoError     0x00
#define EEPROM_BadAddress  0x01
#define EEPROM_I2cError    0x02
#define EEPROM_ParamError  0x03
#define EEPROM_OutOfRange  0x04
#define EEPROM_MallocError 0x05

#define EEPROM_MaxError       6

static string _ErrorMessageEEPROM[EEPROM_MaxError] = {
                                                            "",
                                                            "Bad chip address",
                                                            "I2C error (nack)",
                                                            "Invalid parameter",
                                                            "Data address out of range",
                                                            "Memory allocation error"
                                                          };

class EPROM
{
public:
    enum TypeEeprom {T24AA01=128,T24AA02=256,T24AA04=512,T24AA08=1024,T24AA16=2048,
                     T24AA32=4096,T24AA64=8192,T24AA128=16384,T24AA256=32768,
                     T24AA512=65536,T24AA1024=131072,T24AA1025=131073} Type;
    /**
     * Constructor, initialize the eeprom on i2c interface.
     * @param sda sda i2c pin (PinName)
     * @param scl scl i2c pin (PinName)
     * @param address eeprom address, according to eeprom type (uint8_t)
     * @param type eeprom type (TypeEeprom) 
     * @return none
    */
    EPROM(PinName sda, PinName scl, uint8_t address, TypeEeprom type);
    
    /**
     * Random read byte
     * @param address start address (uint32_t)
     * @param data byte to read (int8_t&)
     * @return none
    */
    int read(uint32_t address, int8_t& data);
    
    /**
     * Random read short
     * @param address start address (uint32_t)
     * @param data short to read (int16_t&)
     * @return none
    */
    int read(uint32_t address, int16_t& data);
    
    /**
     * Random read long
     * @param address start address (uint32_t)
     * @param data long to read (int32_t&)
     * @return none
    */
    int read(uint32_t address, int32_t& data);
    
    /**
     * Random read anything
     * @param address start address (uint32_t)
     * @param data data to read (void *)
     * @param size number of bytes to read (uint32_t)
     * @return none
    */
    int read(uint32_t address, void *data, uint32_t size);
    
    /**
     * Current address read byte
     * @param data byte to read (int8_t&)
     * @return none
    */
    int read(int8_t& data);
    
    /**
     * Sequential read byte
     * @param address start address (uint32_t)
     * @param data bytes array to read (int8_t[]&)
     * @param size number of bytes to read (uint32_t)
     * @return none
    */
    int read(uint32_t address, int8_t *data, uint32_t size);
    
    /**
     * Write byte
     * @param address start address (uint32_t)
     * @param data byte to write (int8_t)
     * @return none
    */
    int write(uint32_t address, int8_t data);
    
    /**
     * Write short
     * @param address start address (uint32_t)
     * @param data short to write (int16_t)
     * @return none
    */
    int write(uint32_t address, int16_t data);
    
    /**
     * Write long
     * @param address start address (uint32_t)
     * @param data long to write (int32_t)
     * @return none
    */
    int write(uint32_t address, int32_t data);
    
    /**
     * Write float
     * @param address start address (uint32_t)
     * @param data float to write (float)
     * @return none
    */
    int write(uint32_t address, float data);
    
    /**
     * Write anything (use the page write mode)
     * @param address start address (uint32_t)
     * @param data data to write (void *)
     * @param size number of bytes to write (uint32_t)
     * @return none
    */
    int write(uint32_t address, void *data, uint32_t size);
    
    /**
     * Write array of bytes (use the page mode)
     * @param address start address (uint32_t)
     * @param data bytes array to write (int8_t[])
     * @param size number of bytes to write (uint32_t)
     * @return none
    */
    int write(uint32_t address, int8_t data[], uint32_t size);
    
    /**
     * Wait eeprom ready
     * @param none
     * @return none
    */
    void ready(void);
    
    /**
     * Get eeprom size in bytes
     * @param none
     * @return size in bytes (uint32_t)
    */
    uint32_t getSize(void);
        
    /**
     * Get eeprom name
     * @param none
     * @return name (const char*)
    */
    const char* getName(void);
    
    /**
     * Clear eeprom (write with 0)
     * @param  none
     * @return none
    */
    void clear(void);
    
     /**
     * Get the current error number (EEPROM_NoError if no error)
     * @param  none
     * @return none
    */
    uint8_t getError(void);
    
    /**
     * Get current error message
     * @param  none
     * @return current error message(std::string)
    */
    std::string getErrorMessage(void)
    { 
      return(_ErrorMessageEEPROM[_errnum]);
    }
    
    I2C *getI2c(){
        return &_i2c;
    }
    
private:
    I2C _i2c;              // Local i2c communication interface instance
    int _address;          // Local i2c address
    uint8_t _errnum;       // Error number
    TypeEeprom _type;      // EEPROM type
    uint8_t _page_write;   // Page write size
    uint8_t _page_number;  // Number of page
    uint32_t _size;        // Size in bytes
    bool checkAddress(uint32_t address); // Check address range
    static const char * const _name[]; // eeprom name
};

#endif
