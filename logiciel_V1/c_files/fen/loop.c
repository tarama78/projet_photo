void loop(t_photos *photos)
{
    SDL_Event event;

    while (gest_event(photos, event) == 0)
    {
	draw(photos);
    }
}
