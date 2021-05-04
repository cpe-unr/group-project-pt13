#ifndef NORMALIZATION_H
#define NORMALIZATION_H
#include <cmath>
#include <vector>
#include "audioProcessing.h"

/**
 * @brief Normalization class handles normalization of WAV files.
 * 
 */
class Normalization : public audioProcessor{
    float maxValue;
    std::vector<float> audio;
public:
    /**
     * @brief Construct a new Normalization object.
     * 
     * @param maxValue - A maximum value for audio level.
     */
    explicit Normalization(float maxValue);
    void process8bitMonoBuffer(unsigned char* buffer, int bufferSize) override;
	void process16bitMonoBuffer(unsigned char* buffer, int bufferSize) override;
};

#endif 
