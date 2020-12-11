#include "fileworker.h"
#include <fstream>
#include "note.h"
#include "json.hpp"
#include <iostream>
using json = nlohmann::json;

FileWorker::FileWorker()
{

}

std::string FileWorker::getfilename(const QDate &date)
{
    return date.toString("yyyyMMdd").toStdString() + ".json";
}

void FileWorker::writeOut(const Note &note, const QDate &date)
{
    json j;

    j["name"] = note.name.toStdString();
    j["text"] = note.text.toStdString();

    std::ofstream f(getfilename(date));

    if(!f.good())
    {
        std::cout << "File never opened" << std::endl;
    }
    else
    {
        f << j.dump(4);
        f.close();
    }
}


Note FileWorker::read(const QDate &date)
{
    std::ifstream f(getfilename(date));

    if(!f.good())
    {
        std::cout << "File never opened" << std::endl;
        throw new std::exception();
    }

    json j;

    try
    {
        f >> j;
    }
    catch (...)
    {
        std::cout << "Parsing error" << std::endl;
    }

    f.close();
    return Note(QString::fromStdString(j["name"]),
            QString::fromStdString(j["text"]));

}

