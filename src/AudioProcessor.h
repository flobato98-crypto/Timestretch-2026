#pragma once

#include <QString>


class AudioProcessor
{

public:

    AudioProcessor();


    bool process(
        const QString& inputFile,
        const QString& outputFile,
        double stretch,
        double pitch,
        int blockMs,
        int overlap
    );


    QString lastError() const;


private:

    QString errorMessage;

};
