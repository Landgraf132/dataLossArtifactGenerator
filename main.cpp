#include <QCoreApplication>
#include <QPainter>
#include <vector>
#include <iostream>
#include <math.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for (int i = 24; i < 26; i++) {
        std::string fileName;

        if (i < 10) {
            fileName = "ref/I0" + std::to_string(i) + ".BMP";
        } else {
            fileName = "ref/I" + std::to_string(i) + ".BMP";
        }

        QImage img;
        std::cout << "fileName: " << fileName << std::endl;
        QString imgName = fileName.c_str();
        QVector<QImage> artifactImgVec;
        artifactImgVec.push_back(QImage("art/art1.bmp"));
        artifactImgVec.push_back(QImage("art/art2.bmp"));
        artifactImgVec.push_back(QImage("art/art3.bmp"));
        artifactImgVec.push_back(QImage("art/art4.bmp"));
        artifactImgVec.push_back(QImage("art/art5.bmp"));
        artifactImgVec.push_back(QImage("art/art6.bmp"));
        artifactImgVec.push_back(QImage("art/art7.bmp"));
        artifactImgVec.push_back(QImage("art/art8.bmp"));
        artifactImgVec.push_back(QImage("art/art9.bmp"));
        QImage refImgVec(imgName);

        srand(time(NULL));
        int verDraw = rand() % 100;
        int artImgNmb = rand() % artifactImgVec.size();

        for (int x = 0; x < refImgVec.width(); x++) {
            for (int y = 0; y < refImgVec.height(); y++) {
                if ((x % 16 == 0) && (y % 16 == 0) && (x < refImgVec.width() - 8)) {
                    verDraw = rand() % 100;
                    artImgNmb = rand() % artifactImgVec.size();

                    if (verDraw == 3) {
                        QPainter p(&refImgVec);
                        p.drawImage(x, y, artifactImgVec[artImgNmb]);
                        p.end();
                    }
                }
            }
        }
        refImgVec.save("out_" + imgName);
        std::cout << "output fileName: out_" << fileName << std::endl;
    }
    return 0;
}
