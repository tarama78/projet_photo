void draw(t_p *p)
{
    char	full_name[100];
    char	letter_add[26];
    char	count_p[100];
    int		i;
    int		j;
    float	zoom;

    zoom = 1;
    if (p->p_change)
    {
	if (p->p[p->p_act].state == DELETE)
	    p->fen.coul_fond = SDL_MapRGB(p->fen.ecran->format, 255, 0, 0);
	else
	    p->fen.coul_fond = SDL_MapRGB(p->fen.ecran->format, 255, 255, 255);
	p->p_change = 0;
	get_full_name(p, p->p_act, full_name);
	p->fen.img = IMG_Load(full_name);
	zoom = fminf(((float)p->fen.size_max_img[0]/p->fen.img->w),
		     ((float)p->fen.size_max_img[1]/p->fen.img->h));
	p->fen.img = zoomSurface(p->fen.img, zoom, zoom, 1);
	p->fen.nom = TTF_RenderText_Blended(p->fen.police, p->p [p->p_act].name,
					    p->fen.coul_txt);
	sprintf(count_p, "%d/%d", (p->p_act + 1), p->nb_p);
	p->fen.count_p = TTF_RenderText_Blended(p->fen.police, count_p,
						p->fen.coul_txt);
    }
    if (p->letter_change)
    {
	p->letter_change = 0;
	if (p->p[p->p_act].state == DELETE)
	    letter_add[0] = '\0';
	else
	{
	    i = -1;
	    j = 0;
	    while (++i < 26)
		if (p->p[p->p_act].letter[i] == 1)
		    letter_add[j++] = i + 65;
	    letter_add[j] = '\0';
	}
	p->fen.letter = TTF_RenderText_Blended(p->fen.police, letter_add,
					       p->fen.coul_txt);
    }
    SDL_FillRect(p->fen.ecran, NULL, p->fen.coul_fond);
    SDL_BlitSurface(p->fen.img, NULL, p->fen.ecran, &p->fen.pos_img);
    SDL_BlitSurface(p->fen.nom, NULL, p->fen.ecran, &p->fen.pos_nom);
    SDL_BlitSurface(p->fen.letter, NULL, p->fen.ecran, &p->fen.pos_letter);
    SDL_BlitSurface(p->fen.count_p, NULL, p->fen.ecran, &p->fen.pos_count_p);
    SDL_Flip(p->fen.ecran);
}
