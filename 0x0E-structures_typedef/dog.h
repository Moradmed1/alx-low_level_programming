#ifndef DOG_H
#define DOG_H

/**
 * struct dog - struct of dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner,s name
 *
 * Description: longer description
 */
struct dog
{
	char *name;
	float age;
	char *owner;

};

void init_dog(struct dog *d, char *name, float age, char *owner);
#endif
