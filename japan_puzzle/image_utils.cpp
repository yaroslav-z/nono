#include "image_utils.h"
#include <stdio.h>
#include <string.h>
#include <cassert>

void image_utils::save_to_bmp(const Image &image, const std::string &path)
{
    size_t h=image.size();
    assert(h);
    size_t w =image[0].size();
    assert(w);

    int filesize = 54 + 3*w*h;
    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
    unsigned char bmppad[3] = {0,0,0};

    bmpfileheader[ 2] = (unsigned char)(filesize    );
    bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
    bmpfileheader[ 4] = (unsigned char)(filesize>>16);
    bmpfileheader[ 5] = (unsigned char)(filesize>>24);

    bmpinfoheader[ 4] = (unsigned char)(       w    );
    bmpinfoheader[ 5] = (unsigned char)(       w>> 8);
    bmpinfoheader[ 6] = (unsigned char)(       w>>16);
    bmpinfoheader[ 7] = (unsigned char)(       w>>24);
    bmpinfoheader[ 8] = (unsigned char)(       h    );
    bmpinfoheader[ 9] = (unsigned char)(       h>> 8);
    bmpinfoheader[10] = (unsigned char)(       h>>16);
    bmpinfoheader[11] = (unsigned char)(       h>>24);

    unsigned char *img = NULL;
    img = (unsigned char *)malloc(3*w*h);
    memset(img,0,3*w*h);

    for(size_t i=0; i<w; i++)
    {
        for(size_t j=0; j<h; j++)
        {
            auto x=i;
            auto y=(h-1)-j;
            auto r = image[y][i].r;
            auto g = image[y][i].g;
            auto b = image[y][i].b;

            img[(x+y*w)*3+2] = (unsigned char)(r);
            img[(x+y*w)*3+1] = (unsigned char)(g);
            img[(x+y*w)*3+0] = (unsigned char)(b);
        }
    }

    FILE *f;
    f = fopen(path.c_str(),"wb");
    fwrite(bmpfileheader,1,14,f);
    fwrite(bmpinfoheader,1,40,f);
    for(int i=0; i<h; i++)
    {
        fwrite(img+(w*(h-i-1)*3),3,w,f);
        fwrite(bmppad,1,(4-(w*3)%4)%4,f);
    }

    fclose(f);
}

Image image_utils::create_image_from_puzzle(const std::vector<std::vector<uint8_t> > &field, std::map<uint8_t, color> &color_map, size_t coef)
{
    Image image;
    auto height = field.size();
    assert(height && "height should be positive");
    auto width = field[0].size();
    assert(width && "width should be positive");
    for(size_t h = 0; h < height;h++)
    {
        assert(width==field[h].size());
        std::vector<color> line(coef * width);
        for(size_t w=0;w<width;w++)
        {
            auto current_color = color_map[field[h][w]];
            for(size_t i=0;i<coef;i++)
            {
                line[coef*w+i]=current_color;
            }
        }
        for(size_t i=0;i<coef;i++)
        {
            image.push_back(line);
        }
    }
    return image;
}

void image_utils::save_to_bmp_black_white_puzzle(const std::vector<std::vector<uint8_t> > &field, const std::__cxx11::string &path)
{
    std::map<uint8_t, color> color_map;
    color_map[0]={255,255,255};
    color_map[1]={0,0,0};
    color_map[255]={150,150,150};
    auto image = create_image_from_puzzle(field, color_map);
    save_to_bmp(image, path);
}
