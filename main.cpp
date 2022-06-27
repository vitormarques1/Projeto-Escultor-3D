#include <iostream>
#include "sculptor.h"
#include <fstream>
#include <iostream>
#include <cstdlib>


int main() {
  // cria um escultor cuja matriz tem 50x50x50 voxels
  Sculptor sonic(50,50,50);

  //cabeça
  sonic.setColor(0,0.2,0.8,1.0); // azul
  sonic.putBox(20,29,20,27,20,28);
  sonic.cutBox(20,21,20,27,20,21);
  sonic.cutBox(20,21,20,27,27,28);
  sonic.cutBox(28,29,20,27,20,21);
  sonic.cutBox(28,29,20,27,27,28);
  sonic.cutBox(20,29,20,21,20,21);
  sonic.cutBox(20,29,20,21,27,28);  
  sonic.cutBox(20,29,26,27,20,21);
  sonic.cutBox(20,29,26,27,27,28);
  sonic.cutBox(20,21,20,21,20,28);
  sonic.cutBox(20,21,26,27,20,28);
  sonic.cutBox(28,29,20,21,20,28);
  sonic.cutBox(28,29,26,27,20,28);

  //orelhas
  sonic.setColor(1,0.8,0.6,1.0);//pele
  sonic.putVoxel(20,26,25);
  sonic.putVoxel(28,26,25);
  sonic.setColor(0,0.2,0.8,1.0); // azul
  sonic.putVoxel(19,26,25);
  sonic.putVoxel(19,25,25);
  sonic.putVoxel(19,27,25);
  sonic.putVoxel(20,27,25);
  sonic.putVoxel(21,27,25);
  sonic.putVoxel(20,26,24);
  sonic.putVoxel(29,26,25);
  sonic.putVoxel(29,27,25);
  sonic.putVoxel(27,27,25);
  sonic.putVoxel(29,25,25);
  sonic.putVoxel(28,27,25);
  sonic.putVoxel(28,26,24);

  //olhos
  sonic.setColor(1.0,1.0,1.0,1.0);//branco
  sonic.putVoxel(22,24,27);
  sonic.putVoxel(22,23,27);
  sonic.putVoxel(22,22,27);
  sonic.putVoxel(23,24,27);
  sonic.setColor(0.2,0.6,0.2,1.0);//verde
  sonic.putVoxel(23,23,27);
  sonic.setColor(0,0,0,1.0);//preto
  sonic.putVoxel(23,22,27);
  sonic.setColor(1.0,1.0,1.0,1.0);//branco
  sonic.putVoxel(24,22,27);
  sonic.putVoxel(25,24,27);
  sonic.putVoxel(26,24,27);
  sonic.putVoxel(26,23,27);
  sonic.putVoxel(26,22,27);
  sonic.setColor(0.2,0.6,0.2,1.0);//verde
  sonic.putVoxel(25,23,27);
  sonic.setColor(0,0,0,1.0);//preto
  sonic.putVoxel(25,22,27);

  //bochecha
  sonic.setColor(1,0.8,0.6,1.0);//pele
  sonic.putBox(21,28,20,22,27,29);

  //nariz
  sonic.setColor(0,0,0,1.0);//preto
  sonic.putVoxel(24,21,29);
  sonic.setColor(0.6,0,0,1.0);//vermelho
  sonic.putVoxel(22,20,29);

  //crista
  sonic.setColor(0,0.2,0.8,1.0); // azul
  sonic.putVoxel(24,27,23);
  sonic.putVoxel(24,27,22);
  sonic.putVoxel(24,27,21);
  sonic.putVoxel(24,27,20);
  sonic.putVoxel(24,27,19);
  sonic.putVoxel(24,27,18);
  sonic.putVoxel(24,27,17);
  sonic.putVoxel(24,27,16);
  sonic.putVoxel(24,27,15);
  sonic.putVoxel(24,26,20);
  sonic.putVoxel(24,26,19);
  sonic.putVoxel(24,26,18);
  sonic.putVoxel(24,26,17);
  sonic.putVoxel(24,26,16);
  sonic.putVoxel(24,25,17);
  sonic.putVoxel(24,25,18);
  sonic.putVoxel(24,25,19);
  sonic.putVoxel(24,24,19);
  sonic.putVoxel(24,24,18);
  sonic.putVoxel(24,23,19);
  sonic.putVoxel(24,22,19);
  sonic.putVoxel(24,22,18);
  sonic.putVoxel(24,22,17);
  sonic.putVoxel(24,22,16);
  sonic.putVoxel(24,22,15);
  sonic.putVoxel(24,21,16);
  sonic.putVoxel(24,21,17);
  sonic.putVoxel(24,21,18);
  sonic.putVoxel(24,21,19);
  sonic.putVoxel(24,20,20);
  sonic.putVoxel(24,20,19);
  sonic.putVoxel(24,20,18);
  sonic.putVoxel(24,20,17);
  sonic.putVoxel(24,19,18);
  sonic.putVoxel(24,19,19);
  sonic.putVoxel(24,19,20);
  sonic.putVoxel(24,19,21);
  sonic.putVoxel(24,18,21);
  sonic.putVoxel(24,17,21);
  sonic.putVoxel(24,17,20);
  sonic.putVoxel(24,17,19);
  sonic.putVoxel(24,17,18);
  sonic.putVoxel(24,17,17);
  sonic.putVoxel(24,16,18);
  sonic.putVoxel(24,16,19);
  sonic.putVoxel(24,16,20);
  sonic.putVoxel(24,16,21);
  sonic.putVoxel(24,15,20);
  sonic.putVoxel(24,15,21);
  sonic.putVoxel(24,15,19);
  
  //corpo
  sonic.setColor(0,0.2,0.8,1.0); // azul
  sonic.putBox(22,27,15,20,22,27);
  sonic.setColor(1,0.8,0.6,1.0);//pele
  sonic.putVoxel(23,18,26);
  sonic.putVoxel(24,18,26);
  sonic.putVoxel(25,18,26);
  sonic.putVoxel(23,17,26);
  sonic.putVoxel(24,17,26);
  sonic.putVoxel(25,17,26);
  sonic.putVoxel(23,16,26);
  sonic.putVoxel(24,16,26);
  sonic.putVoxel(25,16,26);

  //braços
  sonic.setColor(1,0.8,0.6,1.0);//pele
  sonic.putBox(18,22,18,19,25,26);
  sonic.putBox(18,19,18,19,25,29);
  sonic.setColor(1.0,1.0,1.0,1.0);//branco
  sonic.putBox(17,20,17,20,29,32);
  sonic.setColor(1,0.8,0.6,1.0);//pele
  sonic.putBox(27,28,18,19,21,25);
  sonic.putBox(27,28,15,19,20,21);
  sonic.setColor(1.0,1.0,1.0,1.0);//branco
  sonic.putBox(26,29,12,15,19,22);

  //pernas
  sonic.setColor(0,0.2,0.8,1.0); // azul
  sonic.putBox(26,27,15,16,26,30);
  sonic.putBox(26,27,12,16,29,30);
  sonic.setColor(1.0,1.0,1.0,1.0); // branco
  sonic.putBox(25,28,11,12,28,31);
  sonic.setColor(0.8,0.2,0,1.0); // vermelho
  sonic.putBox(25,28,9,11,28,34);
  sonic.setColor(1.0,1.0,1.0,1.0); // branco
  sonic.putBox(25,28,10,11,32,33);
  sonic.setColor(0,0.2,0.8,1.0); // azul
  sonic.putBox(22,23,11,16,23,24);
  sonic.putBox(22,23,11,12,20,24);
  sonic.setColor(1.0,1.0,1.0,1.0); // branco
  sonic.putBox(21,24,10,13,19,20);
  sonic.setColor(0.8,0.2,0,1.0); // vermelho
  sonic.putBox(21,24,7,13,17,19);
  sonic.setColor(1.0,1.0,1.0,1.0); // branco
  sonic.putBox(21,24,8,9,18,19);

  //chao
  sonic.setColor(0.2,0.4,0,1.0); // verde
  sonic.putBox(15,35,6,7,15,35);
  sonic.setColor(0.3,0.6,0,1.0); // verde2
  sonic.putBox(15,35,6,7,15,18);
  sonic.putBox(15,35,6,7,21,24);
  sonic.putBox(15,35,6,7,27,30);
  sonic.putBox(15,35,6,7,33,35);
  sonic.setColor(0.4,0.2,0,1.0); // marrom
  sonic.putBox(15,35,4,6,15,35);
  
  //anel
  sonic.setColor(1.0,0.8,0,1.0);
  sonic.putSphere(24,20,35,5);
  sonic.cutSphere(24,20,36,5);
  sonic.cutSphere(24,20,33,4);
  


  
  // grava a escultura digital no arquivo "sonic.off"
  sonic.writeOFF("sonic.off");
  }
