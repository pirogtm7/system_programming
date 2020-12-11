#ifndef FILEWRITER_H
#define FILEWRITER_H
#include <string>
#include "note.h"



class FileWorker
{
public:
    FileWorker();
    static std::string getfilename(const QDate &date);
    static void writeOut(const Note &note, const QDate &date);
    static Note read(const QDate &date);

};

#endif // FILEWRITER_H
