#include "normalization.h"

using namespace std;

/**
 * @brief Construct a new Normalization:: Normalization object
 * 
 * @param maxValue - Sets a maximum value for the audio volume.
 */
Normalization::Normalization(float maxValue) : maxValue(maxValue){}


/**
 * @brief Normalizes an 8-bit mono WAV file.
 * 
 * @param buffer 
 * @param bufferSize 
 */
void Normalization::process8bitMonoBuffer(unsigned char* buffer, int bufferSize)
{
    float maxValue = 0;
    for (size_t i = 0; i < audio.size(); ++i)
    {
        maxValue = max(maxValue, abs(audio[i]));
    }
    for (size_t i = 0; i < audio.size(); ++i)
    {
        audio[i] = audio[i] / maxValue;
    }
    
}
/**
 * @brief Normalizes a 16-bit mono WAV file.
 * 
 * @param buffer 
 * @param bufferSize 
 */
void Normalization::process16bitMonoBuffer(unsigned char* buffer, int bufferSize)
{
   for (size_t i = 0; i < audio.size(); ++i)
    {
        maxValue = max(maxValue, abs(audio[i]));
    }
    for (size_t i = 0; i < audio.size(); ++i)
    {
        audio[i] = audio[i] / maxValue;
    }
}
