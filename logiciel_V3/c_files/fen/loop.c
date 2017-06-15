/*
** return :
**	0 : stop
**	1 : save
*/

int loop(t_p *p)
{
    int		quit;
    SDL_Event	event;

    quit = 2;
    while (quit == 2)
    {
	quit = gest_event(p, event);
	draw(p);
    }
    return (quit);
}
