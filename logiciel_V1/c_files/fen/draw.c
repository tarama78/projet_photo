void draw(t_photos *photos)
{
    char	full_name[100];
    char	letter_add[26];
    char	count_photos[100];
    int		i;
    int		j;
    float	zoom;

    (void)letter_add;
    (void)count_photos;
    zoom = 1;
    if (photos->photo_change)
    {
	if (photos->photos[photos->photo_act].state == DELETE)
	    photos->fen.coul_fond = SDL_MapRGB(photos->fen.ecran->format, 255, 0, 0);
	else
	    photos->fen.coul_fond = SDL_MapRGB(photos->fen.ecran->format, 255, 255, 255);
	photos->photo_change = 0;
	get_full_name(photos, photos->photo_act, full_name);
	photos->fen.img = IMG_Load(full_name);
	zoom = fminf(((float)photos->fen.size_max_img[0]/photos->fen.img->w),
		     ((float)photos->fen.size_max_img[1]/photos->fen.img->h));
	photos->fen.img = zoomSurface(photos->fen.img, zoom, zoom, 1);
	photos->fen.nom = TTF_RenderText_Blended(photos->fen.police,
						 photos->photos
						 [photos->photo_act].name,
						 photos->fen.coul_txt);
	sprintf(count_photos, "%d/%d", (photos->photo_act + 1),
		photos->nb_photos);
	photos->fen.count_photos = TTF_RenderText_Blended(photos->fen.police,
							  count_photos,
							  photos->fen.coul_txt);
    }
    if (photos->letter_change)
    {
	photos->letter_change = 0;
	if (photos->photos[photos->photo_act].state == DELETE)
	{
	    letter_add[0] = '\0';
	}
	else
	{
	    i = -1;
	    j = 0;
	    while (++i < 26)
	    {
		if (photos->photos[photos->photo_act].letter[i] == 1)
		    letter_add[j++] = i + 65;
	    }
	    letter_add[j] = '\0';
	}
	photos->fen.letter = TTF_RenderText_Blended(photos->fen.police,
						    letter_add,
						    photos->fen.coul_txt);
    }
    SDL_FillRect(photos->fen.ecran, NULL, photos->fen.coul_fond);
    SDL_BlitSurface(photos->fen.img, NULL, photos->fen.ecran,
		    &photos->fen.pos_img);
    SDL_BlitSurface(photos->fen.nom, NULL, photos->fen.ecran,
		    &photos->fen.pos_nom);
    SDL_BlitSurface(photos->fen.letter, NULL, photos->fen.ecran,
		    &photos->fen.pos_letter);
    SDL_BlitSurface(photos->fen.count_photos, NULL, photos->fen.ecran,
		    &photos->fen.pos_count_photos);
    SDL_Flip(photos->fen.ecran);
}
