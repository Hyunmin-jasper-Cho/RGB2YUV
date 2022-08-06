#include <filesystem>
#include <vector>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

typedef std::vector<std::string> str_vec;

str_vec
get_title_of_yuv(fs::path& path);

void
make_ffmpeg_process_text(str_vec& titles, std::string& src, std::string& tar);

int
main(int argc, char * argv[]) {

    /**
     * |-- RGBConvScript
     *      |-- CMakeLists.txt
     *      |-- main.cpp
     *
     * |-- SourceRGB
     *      |-- RGBImage1.png
     *      |-- RGBImage2.png
     *      |-- ...
     * |-- Target folder
     *      |-- converter.sh
     *      |-- (Use converter.sh here, then YUV file generate in this folder)
     */

    if (argc != 3) {
        std::cout << "Sent parameter error: Please ref README.md file. ";
        return EXIT_FAILURE;
    }

    fs::path mp4_path("../..");
    mp4_path /= argv[1];

    str_vec titles_of_yuv = get_title_of_yuv(mp4_path);

    make_ffmpeg_process_text(titles_of_yuv,
                             reinterpret_cast<std::string &>(argv[1]),
                             reinterpret_cast<std::string &>(argv[2]));

    return EXIT_SUCCESS;
}

str_vec
get_title_of_yuv(fs::path& path) {
    str_vec titles;

    fs::directory_iterator itr(path);

    while (itr != fs::end(itr)) {
        const fs::directory_entry& entry = *itr;
        const std::string str_path = entry.path().generic_string();

        std::istringstream iss(str_path);
        std::string token;
        int token_itr = 0;

        while (std::getline(iss, token, '/')) {

            token_itr++;
            if (token_itr == 4) {
                std::istringstream raw_iss(token);
                std::string raw_name;

                std::getline(raw_iss, raw_name, '.');
                titles.emplace_back(raw_name);
            }

        }

        itr++;
    }

    return titles;
}

void
make_ffmpeg_process_text(str_vec& titles, std::string& src, std::string& tar) {
    fs::path path("../..");
    path /= tar + "/converter.sh";
    std::cout << "shell file store path: " << path << std::endl;

    fs::create_directory(path.parent_path());

    std::ofstream ofs(path);
    for (auto& title : titles) {
        ofs << "ffmpeg -i " << "../" << src << "/" << title << ".png " << "-pix_fmt yuv420p ./" << title << ".yuv\n";
    }
    ofs.close();
}