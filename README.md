# IGames

La fonction `RenderData *Update(UpdateData *)` prend un pointeur sur `UpdateData` et retourne un pointeur sur `RenderData` (expliqué après). `Update` calcule une nouvelle image du jeu et la génère dans son retour pour être affiché après.

La fonction `char *Save(std::size_t &)` retourne un tableau de données à sauver et la taille de ce tableau (pour ne pas se baser sur un *null*).

La fonction `void Restore(char *, std::size_t)` prends un tableau de données à restaurer et la taille de ce tableau (pour ne pas se baser sur un *null*).

# IGraph

La fonction `InputData *Render(RenderData *)` prend un pointeur sur `RenderData` et retourne un pointeur sur `InputData`. `Render` affiche les données envoyées par le `RenderData` et retourne les évènements et infos reçus depuis la dernière frame.

# InputData

`InputData` contient les nouvelles données de l'affichage comme ses dimensions mais aussi les évènements comme la liste des touches appuyées ou relachées et les boutons souris.

# UpdateData

`UpdateData` contient le `InputData *` renvoyé par l'affichage précédent plus le temps depuis le dernier appel à `Update`

# RenderData

`RenderData` contient une `queue` des données à dessiner pour garder l'ordre d'affichage.
Les `RenderDatas` de la `queue` sont des structures contenant une liste des types affichables:

* `Spot`: Point 2D;
* `Line`: Ligne;
* `Rect`: Rectangle;
* `FilledRect`: Rectangle rempli;
* `Circle`: Ellipse;
* `FilledCircle`: Ellipse remplie;
* `Sprite`: Tableau de couleurs;

Chaque `RenderDatas` contient aussi une position de départ et un taille (optionnelle pour le `Spot`), ainsi qu'un tableau de couleurs:

* `Spot`, `Line`, `Rect` et `Circle` n'utilisent qu'une couleur;
* `FilledRect` et `FilledCircle` utilisent deux couleurs;
* `Sprite` utilise un tableau de couleurs dont les dimensions sont dans `size`;

# Color

`Color` est un int ou un char[4] selon les besoins.
