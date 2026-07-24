#include "AudioProcessor.h"
#include "signalsmith/stretch/Stretch.h"
#include <sndfile.h>


AudioProcessor::AudioProcessor()
{
    SF_INFO info{};

    SNDFILE* file = sf_open(
        "test.wav",
        SFM_READ,
        &info
    );

    if(file)
    {
        sf_close(file);
    }
}


bool AudioProcessor::process(
    const QString& inputFile,
    const QString& outputFile,
    double stretch,
    double pitch,
    int blockMs,
    int overlap
)
{

    Q_UNUSED(inputFile)
    Q_UNUSED(outputFile)
    Q_UNUSED(stretch)
    Q_UNUSED(pitch)
    Q_UNUSED(blockMs)
    Q_UNUSED(overlap)


    /*
        Signalsmith integration will be added here.

        Current purpose:
        verify the application pipeline.
    */


    errorMessage =
        "Audio engine not connected yet";


    return false;
}



QString AudioProcessor::lastError() const
{
    return errorMessage;
}
