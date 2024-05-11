
# include "mlx_minirt.h"

#define	WIN1_SX		242
#define	WIN1_SY		242
#define	IM1_SX		42
#define	IM1_SY		42
#define	IM3_SX		242
#define	IM3_SY		242

int	xpm1_x;
int	xpm1_y;

int	local_endian;

int	color_map_1(void *win,int w,int h);
int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type);

//int	expose_w1(void *p)
//{
//	mlx_put_image_to_window(getmlx(),w1.win,w3.im,0,0);
//}
//
//int	expose_w2 (void *p)
//{	
//	mlx_put_image_to_window(getmlx(),w2.win,w1.im,0,0);
//	mlx_put_image_to_window(getmlx(),w2.win,w2.im,0,0);
//}

int	key_w1(int key,void *p)
{
	printf("Key in Win1 : %d\n",key);
	if (key==0xFF1B)
		exit(0);
}

int	key_w2(int key,void *p)
{
	printf("Key in Win2 : %d\n",key);
	if (key==0xFF1B)
		exit(0);
}

int	key_w3(int key,void *p, t_mlx *w)
{
	printf("Key in Win3 : %d\n",key);
	if (key==0xFF1B)
		mlx_destroy_window(getmlx(),w->win);
}

int	mouse_w1(int button,int x,int y, void *p)
{
	printf("Mouse in Win1, button %d at %dx%d.\n",button,x,y);
}

int	mouse_w2(int button,int x,int y, void *p)
{
	printf("Mouse in Win2, button %d at %dx%d.\n",button,x,y);
}

int	mouse_w3(int x,int y, void *p)
{
	printf("Mouse moving in Win3, at %dx%d.\n",x,y);
}

int	mlx_test()
{
	int	a;

	t_mlx	w1;
	t_mlx	w2;
	t_mlx	w3;

	printf("MinilibX Test Program\n");
	a = 0x11223344;
	if (((unsigned char *)&a)[0] == 0x11)
		local_endian = 1;
	else
		local_endian = 0;
	printf(" => Local Endian : %d\n",local_endian);
	printf("OK (use_xshm %d pshm_format %d)\n",((t_xvar *)getmlx())->use_xshm,((t_xvar *)getmlx())->pshm_format);

	printf(" => Window1 %dx%d \"Title 1\" ...",WIN1_SX,WIN1_SY);
	if (!(w1.win = mlx_new_window(getmlx(),WIN1_SX,WIN1_SY,"Title1")))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf(" => Colormap sans event ...");
	color_map_1(w1.win,WIN1_SX,WIN1_SY);
	printf("OK\n");
	sleep(2);

	printf(" => Clear Window ...");
	mlx_clear_window(getmlx(),w1.win);
	printf("OK\n");
	sleep(2);
	printf(" => Image1 ZPixmap %dx%d ...",IM1_SX,IM1_SY);
	if (!(w1.im = mlx_new_image(getmlx(),IM1_SX,IM1_SY)))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	w1.data = mlx_get_data_addr(w1.im,&(w1.bpp),&(w1.sl),&(w1.endian));
	printf("OK (bpp1: %d, sizeline1: %d endian: %d type: %d)\n",w1.bpp,w1.sl,&(w1.endian),
	 ((t_img *)w1.im)->type);
	printf(" => Fill Image1 ...");
	color_map_2(w1.data,w1.bpp,w1.sl,IM1_SX,IM1_SY,&(w1.endian), 1);
	printf("OK (pixmap : %d)\n",(int)((t_img *)w1.im)->pix);

	printf(" => Put Image1 ...");
	mlx_put_image_to_window(getmlx(),w1.win,w1.im,20,20);
	printf("OK\n");
	sleep(2);
	printf(" => Destroy Image1 ... ");
	mlx_destroy_image(getmlx(), w1.im);
	printf("OK\n");
	sleep(2);

	printf(" => Image3 ZPixmap %dx%d ...\n",IM3_SX,IM3_SY);
	if (!(w3.im = mlx_new_image(getmlx(),IM3_SX,IM3_SY)))
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf("create w3.im\n");
	w3.data = mlx_get_data_addr(w3.im,&(w3.bpp),&(w3.sl),&(w3.endian));
	printf("OK (bpp3 %d, sizeline3 %d endian3 %d type %d)\n",w3.bpp,w3.sl,&(w3.endian),
	 ((t_img *)w3.im)->type);

	printf(" => Fill Image3 ...");
	color_map_2(w3.data,w3.bpp,w3.sl,IM3_SX,IM3_SY,&(w3.endian), 1);
	printf("OK (pixmap : %d)\n",(int)((t_img *)w3.im)->pix);

	printf(" => Put Image3 ...");
	mlx_put_image_to_window(getmlx(),w1.win,w3.im,20,20);
	printf("OK\n");
	sleep(2);

	printf(" => String ...");
	mlx_string_put(getmlx(),w1.win,5,WIN1_SY/2,0xFF99FF,"String output");
	mlx_string_put(getmlx(),w1.win,15,WIN1_SY/2+20,0x00FFFF,"MinilibX test");
	printf("OK\n");
	sleep(2);

	printf(" => Xpm from file ...");
	if (!(w2.im = mlx_xpm_file_to_image(getmlx(),"/home/pedromar/code/miniRT/src/open.xpm",&xpm1_x,&xpm1_y)))
		{
			printf(" !! KO !!\n");
			exit(1);
		}
	w2.data = mlx_get_data_addr(w2.im,&(w2.bpp),&(w2.sl),&(w2.endian));
	printf("OK (xpm %dx%d)(img bpp2: %d, sizeline2: %d endian: %d type: %d)\n",
	 xpm1_x,xpm1_y,w2.bpp,w2.sl,&(w2.endian),((t_img *)w2.im)->type);
	sleep(2);

	printf(" => Put xpm ...");
	mlx_put_image_to_window(getmlx(),w1.win,w2.im,0,0);
	mlx_put_image_to_window(getmlx(),w1.win,w2.im,100,100);
	printf("OK\n");
	sleep(2);

	printf(" => 2nd window,\n");
	w2.win = mlx_new_window(getmlx(),WIN1_SX,WIN1_SY,"Title2");
	if (!(w1.im = mlx_new_image(getmlx(),IM3_SX, IM3_SY)))
		{
			printf(" !! KO !!\n");
			exit(1);
		}
	w1.data = mlx_get_data_addr(w1.im,&(w1.bpp),&(w1.sl),&(w1.endian));
	color_map_2(w1.data,w1.bpp,w1.sl,IM3_SX,IM3_SY,&(w1.endian), 2);

	printf(" 3rd window, Installing hooks ...");
	w3.win = mlx_new_window(getmlx(),WIN1_SX,WIN1_SY,"Title3");
	//mlx_expose_hook(w1.win,expose_w1,0);
	mlx_mouse_hook(w1.win,mouse_w1,0);
	mlx_key_hook(w1.win,key_w1,0);

	
	mlx_mouse_hook(w2.win,mouse_w2,0);
	mlx_key_hook(w2.win,key_w2,0);
	mlx_key_hook(w3.win,key_w3,0);

	mlx_hook(w3.win, MotionNotify, PointerMotionMask, mouse_w3, 0);

	printf("OK\nNow in Loop. Just play. Esc in 3 to destroy, 1&2 to quit.\n");
	
	mlx_loop(getmlx());
}


int	color_map_1(void *win,int w,int h)
{
	int	x;
	int	y;
	int	color;

	x = w;
	while (x--)
		{
			y = h;
			while (y--)
				{
					color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
		mlx_pixel_put(getmlx(),win,x,y,color);
				}
		}
}


int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type)
{
	int	x;
	int	y;
	int	opp;
	int	dec;
	int	color;
	int	color2;
	unsigned char *ptr;

	opp = bpp/8;
	printf("(opp : %d) ",opp);
	y = h;
	while (y--)
		{
			ptr = data+y*sl;
			x = w;
			while (x--)
				{
		if (type==2)
			color = (y*255)/w+((((w-x)*255)/w)<<16)
				+(((y*255)/h)<<8);
		else
			color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
					color2 = mlx_get_color_value(getmlx(),color);
		dec = opp;
		while (dec--)
			if (endian==local_endian)
				{
		if (endian)
			*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[4-opp+dec];
		else
			*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[dec];
				}
			else
				{
		if (endian)
			*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[opp-1-dec];
		else
			*(ptr+x*opp+dec) = ((unsigned char *)(&color2))[3-dec];
				}
				}
		}
}
