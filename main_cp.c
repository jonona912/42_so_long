int	main(int argc, char **argv)
{
  char  **map;

	if (argc != 2)// && !ft_strstr(argv[1], ".ber"))
	{
		ft_printf("Invalid Input\n");
		return (0);
	}
	map = is_map_valid(argv[1]);
  while (*map)
  {
    printf("%s\n", *map);
    map++;
  }

  int a;

	printf("MinilibX Test Program\n");
	a = 0x11223344;
	if (((unsigned char *)&a)[0] == 0x11)
		local_endian = 1;
	else
		local_endian = 0;
	printf(" => Local Endian : %d\n",local_endian);

	printf(" => Connection ...");
	if (!(mlx = mlx_init())) // establishes connection between software and hardware
	{
		printf(" !! KO !!\n");
		exit(1);
	}
	printf(" => Window1 %dx%d \"Background\" ...",WIN1_SX,WIN1_SY);
  	if (!(win1 = mlx_new_window(mlx,WIN1_SX,WIN1_SY,"Background"))) // opens new window titled Title1
    {
      printf(" !! KO !!\n");
      exit(1);
    }
	printf("OK\n");


  printf(" => Xpm from file ...");
  if (!(im2 = mlx_xpm_file_to_image(mlx,"./images/grass.xpm",&xpm1_x,&xpm1_y)))
    {
      printf(" !! KO !!\n");
      exit(1);
    }
  data2 = mlx_get_data_addr(im2,&bpp2,&sl2,&endian2);
  printf("OK (xpm %dx%d)(img bpp2: %d, sizeline2: %d endian: %d type: %d)\n",
	 xpm1_x,xpm1_y,bpp2,sl2,endian2,((t_img *)im2)->type);
  sleep(2);

  printf(" => Put xpm ...");
  int y_len;
  int x_len;
  y_len = WIN1_SX / xpm1_x;
  x_len = WIN1_SY / xpm1_y;
  int  i = 0;
  int  j = 0;
  while (i < WIN1_SY)
  {
    j = 0;
    while (j < WIN1_SX)
    {
      mlx_put_image_to_window(mlx,win1,im2,j,i);
      j += xpm1_x;
    }
    i += xpm1_y;
  }
  // mlx_put_image_to_window(mlx,win1,im2,0,0);
  // mlx_put_image_to_window(mlx,win1,im2,47,0);
  mlx_key_hook(win1,key_win1,0);
  printf("OK\n");
  sleep(2);



	mlx_loop(mlx);
	return (0);
}
