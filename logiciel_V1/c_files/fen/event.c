int gest_event(t_photos *photos, SDL_Event event)
{
    int		quit;
    int		i;

    quit = 0;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
    {
	quit = 1;
    }
    else if (event.type == SDL_KEYDOWN)
    {
	if (event.key.keysym.sym == SDLK_ESCAPE)
	{
	    quit = 1;
	}
	else if (event.key.keysym.sym == SDLK_DELETE)
	{
	    if (photos->photos[photos->photo_act].state == DELETE)
	    {
		i = -1;
		while (++i < 26)
		{
		    if (photos->photos[photos->photo_act].letter[i] == 1)
		    {
			photos->letter_change = 1;
			photos->photos[photos->photo_act].state = NEW_NAME;
			break;
		    }
		}
		if (photos->photos[photos->photo_act].state == DELETE)
		    photos->photos[photos->photo_act].state = NO_CHANGE;
	    }
	    else
	    {
		del_photos_id(photos, photos->photo_act);
	    }
	    photos->letter_change = 1;
	    photos->photo_change = 1;
	}
	else if (event.key.keysym.sym == SDLK_RIGHT)
	{
	    next_photos(photos);
	}
	else if (event.key.keysym.sym == SDLK_LEFT)
	{
	    prev_photos(photos);
	}
	else if (event.key.keysym.sym == SDLK_BACKSPACE)
	{
	    i = -1;
	    while (++i < 26)
		photos->photos[photos->photo_act].letter[i] = 0;
	    photos->letter_change = 1;
	}
	else if (event.key.keysym.sym >= 97 && event.key.keysym.sym <= 122)
	{
	    if (photos->photos[photos->photo_act].
		letter[event.key.keysym.sym - 97] == 1)
		photos->photos[photos->photo_act].
		    letter[event.key.keysym.sym - 97] = 0;
	    else
		photos->photos[photos->photo_act].
		    letter[event.key.keysym.sym - 97] = 1;
	    photos->letter_change = 1;
	}
    }
    return quit;
}
