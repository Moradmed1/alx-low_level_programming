#include "dog.h"

/**
 * init_dog - initializes a dog
 * @d: the dog name
 * @name: name of dog
 * @age: dog,s age
 * @owner: the owner
 *
 * Return: void.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
