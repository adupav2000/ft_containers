# FT_CONTAINERS #

Implémentez les containers suivants et rendez les fichiers<container>
.hppcorres-pondants :
    pvector, Vous n’avez pas à faire la spécialisationvector<bool>.
    *map
    *stack Elle utilisera votre classe vector comme container sous-jacent par défaut. 
         Cepen-dant, elle restera compatible avec les autres containers, ceux de la STL inclus.
    *iterators_traits
	*reverse_iterator
	*enable_if 
		Oui, il s’agit de C++11 mais vous saurez le refaire en C++98.
		Le but est de vous faire découvrir SFINAE.*is_integral*equalet/oulexicographical_compare*std::pair*std::make_pair5

	is_integral
	*equalet/oulexicographical_compare
	*std::pair
	*std::make_pair

	*Pour les surcharges non-membres, le mot-clé friend est autorisé .
    Chaque utilisa-tion defrienddoit être justifiée et sera vérifiée en évaluation
	*Bien entendu, pour implémentermap::value_compare, le mot-cléfriendest au-torisé.
	*Comparez lessortieset lesperformances / temps(vos containers peuvent être jusqu’à 20 fois plus lents que les originaux).
	*Pour tester vos containers :ft::<container>


## Des liens utile
[PDF standart de C++98][https://www.lirmm.fr/~ducour/Doc-objets/ISO+IEC+14882-1998.pdf]
