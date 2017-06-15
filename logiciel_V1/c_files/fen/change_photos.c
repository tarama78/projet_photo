void next_photos(t_photos *photos)
{
    photos->photo_act++;
    if (photos->photo_act >= photos->nb_photos)
	photos->photo_act = 0;
    photos->photo_change = 1;
    photos->letter_change = 1;
    photos->photos[photos->photo_act].view = 1;
}

void prev_photos(t_photos *photos)
{
    photos->photo_act--;
    if (photos->photo_act < 0)
	photos->photo_act = photos->nb_photos - 1;
    photos->photo_change = 1;
    photos->letter_change = 1;
    photos->photos[photos->photo_act].view = 1;
}
