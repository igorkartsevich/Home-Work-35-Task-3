#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#define DEF_FILE_EXTENSION ".jpg"
#define DEF_FILE_PATH "C:/Users/Igor Kartsevich/Pictures"

int main()
{
    std::vector<std::filesystem::path> fileList;

    std::string fileExtension = DEF_FILE_EXTENSION;
    std::filesystem::path filePath(DEF_FILE_PATH);

    auto recursiveGetFileNamesByExtension = [&fileList] (std::filesystem::path filePath, const std::string& fileExtension) {
        for (auto& p : std::filesystem::recursive_directory_iterator(filePath))
            if(p.is_regular_file())
                if (!p.path().extension().compare(fileExtension))
                    fileList.emplace_back(p.path().filename());

        return;
    };

    recursiveGetFileNamesByExtension(filePath, fileExtension);

    return 0;
}