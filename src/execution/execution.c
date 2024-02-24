/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:54:32 by gfernand          #+#    #+#             */
/*   Updated: 2024/02/08 20:36:28 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	execution(void)
{
	t_cub	cub;
    t_ray   ray;

	cub.mlx = mlx_init();
	cub.win = mlx_new_window(cub.mlx, W_WIDTH, W_HEIGHT, "cub3D");
	if (!cub.win)
		exit_mssg("Wrong window\n");
	//cub.img = mlx_new_image(cub.mlx, W_WIDTH, W_HEIGHT);
	cub.px = 100;
	cub.py = 100;
    ray.angle = 0;
    cub.ray = ray;
	drawMap2D(cub, ray);
	//mlx_put_image_to_window(cub.mlx, cub.win, cub.img, 0, 0);

	window(&cub);
}

/*
void    ray_casting(void)
{
	t_ray	ray;
	
    para(int x = posx; x < weigth; x++)
    {
      //calcular la posición y dirección del rayo
       double cameraX = 2 * x / double(w) - 1; //coordenada x en el espacio de la cámara
       double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planoY * cámaraX;
	}

	delta_x = sqrt(1 + (rdir_y * rdir_y) / (rdir_x * rdir_x));
	delta_y = sqrt(1 + (rdir_x * rdir_x) / (rdir_y * rdir_y));
		Es lo mismo que:
	deltaDistX = abs(1 / rayDirX);
	deltaDistY = abs(1 / rayDirY);

	if (rdir_x < 0)
	{
    	stepX = -1;
        sideDistX = (posX - mapX) * delta_x;
    }
    else
    {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posx) * delta_x;
    }
    if (rdir_y < 0)
    {
        stepY = -1;
        sideDistY = (posY - mapY) * delta_y;
    }
    else
    {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * delta_y;
    }

}
*/

/*void drawRays2D()
{
 glColor3f(0,1,1); glBegin(GL_QUADS); glVertex2i(526,  0); glVertex2i(1006,  0); glVertex2i(1006,160); glVertex2i(526,160); glEnd();	
 glColor3f(0,0,1); glBegin(GL_QUADS); glVertex2i(526,160); glVertex2i(1006,160); glVertex2i(1006,320); glVertex2i(526,320); glEnd();	 	
	
 int r,mx,my,mp,dof,side; float vx,vy,rx,ry,ra,xo,yo,disV,disH; 
 
 ra=FixAng(pa+30);                                                              //ray set back 30 degrees
 
 for(r=0;r<60;r++)
 {
  //---Vertical--- 
  dof=0; side=0; disV=100000;
  float Tan=tan(degToRad(ra));
       if(cos(degToRad(ra))> 0.001){ rx=(((int)px>>6)<<6)+64;      ry=(px-rx)*Tan+py; xo= 64; yo=-xo*Tan;}//looking left
  else if(cos(degToRad(ra))<-0.001){ rx=(((int)px>>6)<<6) -0.0001; ry=(px-rx)*Tan+py; xo=-64; yo=-xo*Tan;}//looking right
  else { rx=px; ry=py; dof=8;}                                                  //looking up or down. no hit  

  while(dof<8) 
  { 
   mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;                     
   if(mp>0 && mp<mapX*mapY && map[mp]==1){ dof=8; disV=cos(degToRad(ra))*(rx-px)-sin(degToRad(ra))*(ry-py);}//hit         
   else{ rx+=xo; ry+=yo; dof+=1;}                                               //check next horizontal
  } 
  vx=rx; vy=ry;

  //---Horizontal---
  dof=0; disH=100000;
  Tan=1.0/Tan; 
       if(sin(degToRad(ra))> 0.001){ ry=(((int)py>>6)<<6) -0.0001; rx=(py-ry)*Tan+px; yo=-64; xo=-yo*Tan;}//looking up 
  else if(sin(degToRad(ra))<-0.001){ ry=(((int)py>>6)<<6)+64;      rx=(py-ry)*Tan+px; yo= 64; xo=-yo*Tan;}//looking down
  else{ rx=px; ry=py; dof=8;}                                                   //looking straight left or right
 
  while(dof<8) 
  { 
   mx=(int)(rx)>>6; my=(int)(ry)>>6; mp=my*mapX+mx;                          
   if(mp>0 && mp<mapX*mapY && map[mp]==1){ dof=8; disH=cos(degToRad(ra))*(rx-px)-sin(degToRad(ra))*(ry-py);}//hit         
   else{ rx+=xo; ry+=yo; dof+=1;}                                               //check next horizontal
  } 
  
  glColor3f(0,0.8,0);
  if(disV<disH){ rx=vx; ry=vy; disH=disV; glColor3f(0,0.6,0);}                  //horizontal hit first
  glLineWidth(2); glBegin(GL_LINES); glVertex2i(px,py); glVertex2i(rx,ry); glEnd();//draw 2D ray
    
  int ca=FixAng(pa-ra); disH=disH*cos(degToRad(ca));                            //fix fisheye 
  int lineH = (mapS*320)/(disH); if(lineH>320){ lineH=320;}                     //line height and limit
  int lineOff = 160 - (lineH>>1);                                               //line offset
  
  glLineWidth(8);glBegin(GL_LINES);glVertex2i(r*8+530,lineOff);glVertex2i(r*8+530,lineOff+lineH);glEnd();//draw vertical wall  

  ra=FixAng(ra-1);                                                              //go to next ray
 }
}*/
