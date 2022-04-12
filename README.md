# FT\_CONTAINERS 

## Implémentez les containers suivants et rendez les fichiers\<container\>
### .hpp correspondants 
    - vector, Vous n’avez pas à faire la spécialisationvector \<bool\>.
    - map
    - stack : Elle utilisera votre classe vector comme container sous-jacent par défaut.  Cependant, elle restera compatible avec les autres containers, ceux de la STL inclus.
    - iterators\_traits
	- reverse\_iterator
	- enable\_if Oui, il s’agit de C++11 mais vous saurez le refaire en C++98.  Le but est de vous faire découvrir SFINAE.
    - is\_integral
    - equalet/oulexicographical\_compare
    - std::pair
    - std::make\_pair

	- is\_integral
	- equalet/oulexicographical\_compare
	- std::pair
	- std::make\_pair

### Précisions
	- Pour les surcharges non-membres, le mot-clé friend est autorisé .
    - Chaque utilisa-tion defrienddoit être justifiée et sera vérifiée en évaluation
	- Bien entendu, pour implémentermap::value\_compare, le mot-cléfriendest au-torisé.
	- Comparez lessortieset lesperformances / temps(vos containers peuvent être jusqu’à 20 fois plus lents que les originaux).
	- Pour tester vos containers :ft::\<container\>


## Des liens utile
[PDF standart de C++98](https://www.lirmm.fr/~ducour/Doc-objets/ISO+IEC+14882-1998.pdf)
