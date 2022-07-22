#include <filesystem>
#include <sstream>
#include <vector>
#include <fstream>

namespace fs = std::filesystem;

typedef std::vector<std::string> str_vec;

str_vec
get_title_of_yuv(fs::path& path);

void
make_ffmpeg_process_text(str_vec& titles);

const std::string
bit = "10bit_420";

int
main() {

    fs::path mp4_path("../..");
    mp4_path /= bit + "/mp4";

    str_vec titles_of_yuv = get_title_of_yuv(mp4_path);

    make_ffmpeg_process_text(titles_of_yuv);

    return 0;
}

str_vec
get_title_of_yuv(fs::path& path) {
    str_vec titles;

    fs::directory_iterator itr(path);

    while (itr != fs::end(itr)) {
        const fs::directory_entry& entry = *itr;
        const std::string str_path = entry.path().u8string();

        std::istringstream iss(str_path);
        std::string token;
        int token_itr = 0;

        while (std::getline(iss, token, '/')) {

            token_itr++;
            if (token_itr == 5) {
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
make_ffmpeg_process_text(str_vec& titles) {
    fs::path path("../..");
    path /= bit + "/MPEG2YUV";

    fs::create_directory(path.parent_path());

    std::ofstream ofs(path);
    for (auto& title : titles) {
        ofs << "ffmpeg -i " << "./mp4/" << title << ".mp4 " << "./yuv/" << title << ".yuv\n";
    }
    ofs.close();
}