void close_fen(t_p *p)
{
    SDL_FreeSurface(p->fen.ecran);
    SDL_FreeSurface(p->fen.img);
    SDL_FreeSurface(p->fen.nom);
    SDL_FreeSurface(p->fen.letter);
    SDL_FreeSurface(p->fen.count_p);
    SDL_Quit();
}
