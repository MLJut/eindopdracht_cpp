#include "LocalFetcher.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <windows.h>
#include <ShObjIdl.h>

#include "../../Misc/Types.hpp"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

std::string LocalFetcher::Fetch()
{
    std::string path = this->GetFilePath();

    if (path == "")
    {
        std::runtime_error("LocalFetcher::Fetch - Path was empty");
    }

    return path;
}

// fix indentation
std::string LocalFetcher::GetFilePath()
{
    std::string strFilePath;
    HRESULT hr = CoInitializeEx(NULL, 
                                COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE
    );

    if (SUCCEEDED(hr))
    {
        IFileOpenDialog *pFileOpen;

        // Create the FileOpenDialog object.
        hr = CoCreateInstance(CLSID_FileOpenDialog, 
                              NULL, 
                              CLSCTX_ALL, 
                              IID_IFileOpenDialog, 
                              reinterpret_cast<void**>(&pFileOpen)
        );

        if (SUCCEEDED(hr))
        {
            // Show the Open dialog box.
            hr = pFileOpen->Show(NULL);

            // Get the file name from the dialog box.
            if (SUCCEEDED(hr))
            {
                IShellItem *pItem;
                hr = pFileOpen->GetResult(&pItem);
                if (SUCCEEDED(hr))
                {
                    PWSTR pszFilePath;
                    hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);   
                    const wchar_t *wstrFilePath = pszFilePath;

                    mbstate_t state;
                    memset(&state, 0, sizeof state);
                    size_t len = 1 + wcsrtombs(NULL, &wstrFilePath, 0, &state);
                    char chrFilePath[len];
                    wcsrtombs(chrFilePath, &wstrFilePath, len, &state);
                    strFilePath = chrFilePath;

                    // Display the file name to the user.
                    if (SUCCEEDED(hr))
                    {
                        CoTaskMemFree(pszFilePath);
                    }
                    delete wstrFilePath;
                    pItem->Release();
                }
                // delete pItem;
            }
            pFileOpen->Release();
            // delete pFileOpen;
        }
        CoUninitialize();
    }
    return strFilePath;
}
