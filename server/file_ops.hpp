#pragma once

#include <iostream>
#include <string>
#include <filesystem>
#include <vector>

using namespace std;
namespace fs = filesystem;

namespace FileOps
{
    vector<string> files;
    vector<string> directories;

    void listContent()
    {
        string path = "./server_files";
        for (const auto &entry : fs::directory_iterator(path))
        {
            if (entry.is_regular_file())
            {
                files.push_back(entry.path().filename().string());
            }
            else if (entry.is_directory())
            {
                directories.push_back(entry.path().filename().string());
            }
        }
        cout << "\nFiles: \n";
        if (files.empty())
        {
            cout << "(NONE)\n\n";
        }
        else
        {
            for (string file : files)
            {
                cout << "-" << file << endl;
            }
        }

        cout << "\nDirectories" << endl;
        if (!directories.empty())
        {
            for (string directory : directories)
            {
                cout << "-" << directory << endl;
            }
        }
        else
        {
            cout << "(NONE)\n";
        }
    }

}