void create_fen(t_p *p, int width, int height)
{
    char path_police[100];

    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("logiciel de p", NULL);
    p->fen.ecran = SDL_SetVideoMode(width, height, 32,
				    SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (p->fen.ecran == NULL)
    {
	fprintf(stderr, "impossible de charger l'ecran : %s\n", SDL_GetError());
	exit(EXIT_FAILURE);
    }
    p->fen.coul_fond = SDL_MapRGB(p->fen.ecran->format, 255, 255, 255);
    p->fen.size_max_txt[0] = width;
    p->fen.size_max_txt[1] = 25;
    p->fen.size_max_img[0] = width;
    p->fen.size_max_img[1] = height - 25;
    p->fen.pos_img.x = 0;
    p->fen.pos_img.y = p->fen.size_max_txt[1];
    SDL_EnableKeyRepeat(100, 100);
    TTF_Init();
    strcpy(path_police, p->path_prog);
    strcat(path_police, "/police/cooper.ttf");
    p->fen.police = TTF_OpenFont(path_police, 25);
    p->fen.coul_txt.r = 0;
    p->fen.coul_txt.g = 0;
    p->fen.coul_txt.b = 0;
    p->fen.pos_nom.x = 0;
    p->fen.pos_nom.y = 0;
    p->fen.pos_letter.x = p->fen.size_max_txt[0] / 2;
    p->fen.pos_letter.y = 0;
    p->fen.pos_count_p.x = width - 140;
    p->fen.pos_count_p.y = 0;
}
