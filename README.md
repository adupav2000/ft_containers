# FT\_CONTAINERS 

## Implémentez les containers suivants et rendez les fichiers\<container\>
### .hpp correspondants 
- [❌] vector, Vous n’avez pas à faire la spécialisationvector <bool>.
- [❌] map
- [❌] stack : Elle utilisera votre classe vector comme container sous-jacent par défaut.
Cependant, elle restera compatible avec les autres containers, ceux de la STL inclus.
- [❌] iterators_traits
- [❌] reverse_iterator
- [❌] enable_if Oui, il s’agit de C++11 mais vous saurez le refaire en C++98. Le but est de vous faire découvrir SFINAE.
- [❌] is_integral
- [❌] equal et/ou lexicographical_compare
- [❌] std::pair
- [❌] std::make_pair

### Précisions
- Pour les surcharges non-membres, le mot-clé friend est autorisé .
- Chaque utilisation de friend doit être justifiée et sera vérifiée en évaluation
- Bien entendu, pour implémentermap::value_compare, le mot-cléfriendest autorisé.
- Comparez les sortieset les performances / temps(vos containers peuvent être jusqu’à 20 fois plus lents que les originaux).
- Pour tester vos containers :ft::<container>

## Des liens utile
[PDF standart de C++98](https://www.lirmm.fr/~ducour/Doc-objets/ISO+IEC+14882-1998.pdf)

## Les doutes qui m'ont fait perdre du temps
- pas de point .tpp ou .cpp pour les container (oui c'est dans le titre je sais)
