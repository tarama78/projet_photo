/*
** return :
**	0 : stop
**	1 : save
**	2 : continue
*/

int gest_event(t_p *p, SDL_Event event)
{
    int		quit;
    int		i;

    quit = 2;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
	quit = 0;
    else if (event.type == SDL_KEYDOWN)
    {
	if (event.key.keysym.sym == SDLK_ESCAPE)
	    quit = 0;
	else if (event.key.keysym.sym == SDLK_DELETE ||
		 event.key.keysym.sym == SDLK_UP)
	{
	    if (p->p[p->p_act].state == DELETE)
	    {
		i = -1;
		while (++i < 26)
		    if (p->p[p->p_act].letter[i] == 1)
		    {
			p->letter_change = 1;
			p->p[p->p_act].state = NEW_NAME;
			break;
		    }
		if (p->p[p->p_act].state == DELETE)
		    p->p[p->p_act].state = NO_CHANGE;
	    }
	    else
		del_p_id(p, p->p_act);
	    p->letter_change = 1;
	    p->p_change = 1;
	}
	else if (event.key.keysym.sym == SDLK_RIGHT)
	    next_p(p);
	else if (event.key.keysym.sym == SDLK_LEFT)
	    prev_p(p);
	else if (event.key.keysym.sym == SDLK_BACKSPACE)
	{
	    i = -1;
	    while (++i < 26)
		p->p[p->p_act].letter[i] = 0;
	    p->letter_change = 1;
	}
	else if (event.key.keysym.mod == KMOD_LCTRL)
	{
	    if (event.key.keysym.sym == SDLK_s)
	    {
		printf(">>> save\n");
		quit = 1;
	    }
	}
	else if (event.key.keysym.sym >= 97 && event.key.keysym.sym <= 122)
	{
	    if (p->p[p->p_act].letter[event.key.keysym.sym - 97] == 1)
		p->p[p->p_act].letter[event.key.keysym.sym - 97] = 0;
	    else
		p->p[p->p_act].letter[event.key.keysym.sym - 97] = 1;
	    p->letter_change = 1;
	}
    }
    return quit;
}
