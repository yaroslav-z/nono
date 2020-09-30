#ifndef IMAGE_UTILS_H
#define IMAGE_UTILS_H

#include <stdint.h>
#include <vector>
#include <map>
#include <string>

struct color
{
    uint8_t r,g,b;
};

typedef std::vector<std::vector<color> > Image;

class image_utils
{
public:
    static void save_to_bmp(const Image& image, const std::string& path);
    static Image create_image_from_puzzle(const std::vector<std::vector<uint8_t> >& field, std::map<uint8_t, color>& color_map, size_t coef = 10 );
    static void save_to_bmp_black_white_puzzle(const std::vector<std::vector<uint8_t> >& field, const std::string& path);
};

#endif // IMAGE_UTILS_H
