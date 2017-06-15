void create_fen(t_photos *photos, int width, int height)
{
    char path_police[100];

    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("logiciel de photos", NULL);
    photos->fen.ecran = SDL_SetVideoMode(width, height, 32,
					 SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (photos->fen.ecran == NULL)
    {
	fprintf(stderr, "impossible de charger l'ecran : %s\n", SDL_GetError());
	exit(EXIT_FAILURE);
    }
    photos->fen.coul_fond = SDL_MapRGB(photos->fen.ecran->format, 255, 255, 255);
    photos->fen.size_max_txt[0] = width;
    photos->fen.size_max_txt[1] = 25;
    photos->fen.size_max_img[0] = width;
    photos->fen.size_max_img[1] = height - 25;
    photos->fen.pos_img.x = 0;
    photos->fen.pos_img.y = photos->fen.size_max_txt[1];
    SDL_EnableKeyRepeat(100, 100);
    TTF_Init();
    strcpy(path_police, photos->path_prog);
    strcat(path_police, "/police/cooper.ttf");
    photos->fen.police = TTF_OpenFont(path_police, 25);
    photos->fen.coul_txt.r = 0;
    photos->fen.coul_txt.g = 0;
    photos->fen.coul_txt.b = 0;
    photos->fen.pos_nom.x = 0;
    photos->fen.pos_nom.y = 0;
    photos->fen.pos_letter.x = photos->fen.size_max_txt[0] / 2;
    photos->fen.pos_letter.y = 0;
    photos->fen.pos_count_photos.x = width - 140;
    photos->fen.pos_count_photos.y = 0;
}
