#pragma once

#include<iostream>
#include<iomanip>

#include"List.h"

using namespace std;

class Warrior;


class Skill
{
public:
	virtual void execute(Warrior* w) = 0;
};


class FireBall : public Skill
{
public:
	virtual void execute(Warrior* w) override;
};


class Warrior
{
	int hp;
	int damage;

protected:
	Skill* skill;

public:
	Warrior(int hp, int damage, Skill* skill = nullptr) : hp(hp), damage(damage), skill(skill){ }
	virtual ~Warrior() {}
	int getHP() { return hp; }
	int getDamage() { return damage; }
	void setHP(int h) { hp = h; }
	void setDamage(int d) { damage = d; }

	virtual void attack(Warrior* w) = 0;

	friend ostream& operator<<(ostream& out, const Warrior* w);

	virtual ostream& print(ostream& out) const
	{
		out << " HP : " << hp << ", Damege : " << damage << endl;
		return out;
	}

};

ostream& operator<<(ostream& out, const Warrior* w)
{
	out << setw(12) << left << setfill('.');
	return w->print(out);
}


void FireBall::execute(Warrior* w)
{
	cout << "Skill FireBall -> " << w << endl;
}

class Light : public Warrior
{
public:
	Light(int hp, int damage, Skill* skill) : Warrior(hp, damage, skill)	{}
};


class Dark : public Warrior
{
public:
	Dark(int hp, int damage) : Warrior(hp, damage) {}
};

class Archer : public Light
{
	//

public:
	Archer(int hp, int damage, Skill* skill = nullptr) : Light(hp, damage, skill)	{ }

	virtual void attack(Warrior* w) override
	{
		cout << "Archer fight" << endl;

		w->setHP(w->getHP() - getDamage());

		// rnd
		if (skill)
			skill->execute(w);
	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Archer";
		return Warrior::print(out);
	}
};

class Rider : public Light
{
	//

public:
	Rider(int hp, int damage, Skill* skill = nullptr) : Light(hp, damage, skill) {}

	virtual void attack(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Rider";
		return Warrior::print(out);
	}
};

class Swordsman : public Light
{
	//

public:
	Swordsman(int hp, int damage, Skill* skill = nullptr) : Light(hp, damage, skill) {}

	virtual void attack(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Swordsman";
		return Warrior::print(out);
	}
};

class Ork : public Dark
{
	//

public:
	Ork(int hp, int damage) : Dark(hp, damage) {}

	virtual void attack(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Ork";
		return Warrior::print(out);
	}
};

class Zombe : public Dark
{
	//

public:
	Zombe(int hp, int damage) : Dark(hp, damage) {}

	virtual void attack(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Zombe";
		return Warrior::print(out);
	}
};

class Skeleton : public Dark
{
	//

public:
	Skeleton(int hp, int damage) : Dark(hp, damage) {}

	virtual void attack(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Skeleton";
		return Warrior::print(out);
	}
};


class WarOfWord
{
	List<Light*> ligts;
	List<Dark*> darks;

public:
	WarOfWord(int size)
	{
		Light* l = nullptr;
		for (size_t i = 0; i < size; i++)
		{
			int rnd = rand() % 3;
			switch (rnd)
			{
			case 0: l = new Archer(rand() % 20 + 50, rand() % 10 + 10, new FireBall); break;
			case 1: l = new Rider(rand() % 30 + 50, rand() % 10 + 10); break;
			case 2: l = new Swordsman(rand() % 20 + 50, rand() % 10 + 10); break;
			}
			ligts.push_back(l);
		}

		Dark* d = nullptr;
		for (size_t i = 0; i < size; i++)
		{
			int rnd = rand() % 3;
			switch (rnd)
			{
			case 0: d = new Ork(rand() % 20 + 50, rand() % 10 + 10); break;
			case 1: d = new Zombe(rand() % 30 + 50, rand() % 10 + 10); break;
			case 2: d = new Skeleton(rand() % 20 + 50, rand() % 10 + 10); break;
			}
			darks.push_back(d);
		}
	}

	void print()
	{
		cout << "         ---- LIGHT ----" << "                  " << "   ----- DARKS -----" << endl;

		ligts.print();

		cout << endl;

		darks.print(40, 1);
	}

	void game()
	{
		while (ligts.getSize() > 0 && darks.getSize() > 0)
		{
			system("cls");
			print();
			int l_ind = rand() % ligts.getSize();
			int d_ind = rand() % darks.getSize();
			cout << "--------------------------------" << endl;
			cout << ligts[l_ind] << endl;
			cout << darks[d_ind] << endl;
			Warrior* lose = fight(ligts[l_ind], darks[d_ind]);
			if (lose == ligts[l_ind])
			{
				ligts.remove(l_ind);
			}
			else if (lose == darks[d_ind])
			{
				darks.remove(d_ind);
			}
			system("pause");
		}
	}

	Warrior* fight(Warrior* w1, Warrior* w2)
	{
		Warrior *f, *s;
		//
		f = w1;
		s = w2;


		// TODO
		f->attack(s);
		// TODO
		s->attack(f);

		return w2;
	}
};