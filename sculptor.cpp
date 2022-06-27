#include <iostream>
#include "sculptor.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

Sculptor::Sculptor(int nx1, int ny1, int nz1){
    nx = nx1;
    ny = ny1;
    nz = nz1;
    r = 0.5;
    g = 0.5; 
    b = 0.5;
    a = 1;
  
  // Alocação dinâmica da matriz 3d
    v = new Voxel**[nx];
     for (int i =0; i<nx; i++){
      v[i] = new Voxel*[ny];

     for (int j =0; j<ny; j++){
       v[i][j]= new Voxel[nz];
      }
    }
}

Sculptor::~Sculptor(){
    for(int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
               delete[] v[i][j];
            }
        }
        for (int i=0; i <nx; i++){
            delete[] v[i];
        }

        delete[] v;

        nx = 0;
        ny = 0;
        nz = 0;
};

//funçoes
void Sculptor::setColor(float r,float g,float b, float alpha){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = alpha;
}
void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;    
}
void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}
void Sculptor::putBox(int x0_, int x1_, int y0_, int y1_, int z0_, int z1_){
    for(int x = x0_; x<x1_; x++){
       for (int y = y0_; y<y1_; y++){
           for (int z = z0_; z<z1_; z++){
               v[x][y][z].isOn=true;
               v[x][y][z].r = r;
               v[x][y][z].g = g;
               v[x][y][z].b = b;
               v[x][y][z].a = a;
           }
       }
    }
    
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for(int x = x0; x<x1; x++){
       for (int y = y0; y<y1; y++){
           for (int z = z0; z<z1; z++){
               v[x][y][z].isOn = false;
           }
       }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
  for(int i = -radius; i<=radius; i++){
      for(int j = -radius; j<=radius; j++){
          for(int k = -radius; k<=radius; k++){
         
            if ((i*i+j*j+k*k) < radius*radius){
              putVoxel(i+xcenter,j+ycenter,k+zcenter);
            }
          }
      }
  }

}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
  for(int i = -radius; i<radius; i++){
      for(int j = -radius; j<radius; j++){
          for(int k = -radius; k<radius; k++){
            if((i*i+j*j+k*k) < radius*radius){
              cutVoxel(i+xcenter,j+ycenter,k+zcenter);
            }
          }
      }
  }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
   float newx, newy, newz;

    for (int x = 0; x < nx; x++){
        for (int y = 0; y < ny; y++){
            for (int z = 0; z < nz; z++){
            newx = ((float)(x-xcenter)*(float)(x-xcenter))/(rx * rx);
            newy = ((float)(y-ycenter)*(float)(y-ycenter))/(ry * ry);
            newz = ((float)(z-zcenter)*(float)(z-zcenter))/(rz * rz);

            if ((newx + newy + newz) < 1){
                putVoxel(x,y,z);
            }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
   double newx, newy, newz;

    for (int x = 0; x < nx; x++){
        for (int y = 0; y < ny; y++){
            for (int z = 0; z < nz; z++){
            newx = ((float)(x-xcenter)*(float)(x-xcenter))/(rx * rx);
            newy = ((float)(y-ycenter)*(float)(y-ycenter))/(ry * ry);
            newz = ((float)(z-zcenter)*(float)(z-zcenter))/(rz * rz);

            if ((newx + newy + newz) < 1){
                cutVoxel(x,y,z);
            }
            }
        }
    }
}

void Sculptor::writeOFF(char *filename){
    int total, index;
    ofstream arquivo;
    total = 0;
    arquivo.open(filename);
    arquivo << "OFF\n";

    for (int i=0; i < nx; i++){
        for (int j = 0; j <ny; j++){
            for (int k=0; k <nz; k++){
              if(v[i][j][k].isOn == true){
                total++;
              }
            }
        }
    }

    arquivo << total * 8 << " " << total * 6 << " " << 0 << "\n";

    for (int i=0; i < nx; i++){
        for (int j = 0; j <ny; j++){
            for (int k=0; k <nz; k++){
              if(v[i][j][k].isOn == true){
                arquivo << i - 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n" << flush;
                arquivo << i - 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n" << flush;
                arquivo << i + 0.5 << " " << j - 0.5 << " " << k - 0.5 << "\n" << flush;
                arquivo << i + 0.5 << " " << j + 0.5 << " " << k - 0.5 << "\n" << flush;
                arquivo << i - 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n" << flush;
                arquivo << i - 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n" << flush;
                arquivo << i + 0.5 << " " << j - 0.5 << " " << k + 0.5 << "\n" << flush;
                arquivo << i + 0.5 << " " << j + 0.5 << " " << k + 0.5 << "\n" << flush;
              }
            }
        }
    }

    total = 0;

    for (int i=0; i < nx; i++){
        for (int j = 0; j < ny; j++){
            for (int k=0; k < nz; k++){
              if(v[i][j][k].isOn == true){
                index = total*8;
                arquivo << fixed;

                arquivo << 4 << " " << index + 0 << " " << index + 3 << " " << index + 2 << " " << index + 1 << " ";
                arquivo << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " <<setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                arquivo << 4 << " " << index + 4 << " " << index + 5 << " " << index + 6 << " " << index + 7 << " ";
                arquivo << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                arquivo << 4 << " " << index + 0 << " " << index + 1 << " " << index + 5 << " " << index + 4 << " ";
                arquivo << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                arquivo << 4 << " " << index + 0 << " " << index + 4 << " " << index + 7 << " " << index + 3 << " ";
                arquivo << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                arquivo << 4 << " " << index + 7 << " " << index + 6 << " " << index + 2 << " " << index + 3 << " ";
                arquivo << setprecision(2) << v[i][j][k].r << " " <<setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " <<setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                arquivo << 4 << " " << index + 1 << " " << index + 2 << " " << index + 6 << " " << index + 5 << " ";
                arquivo << setprecision(2) << v[i][j][k].r << " " << setprecision(2) << v[i][j][k].g << " " << setprecision(2) << v[i][j][k].b << " " << setprecision(2) << v[i][j][k].a << setprecision(2) << "\n";

                total++;
              }
            }
        }
    }

    arquivo.close();
}
