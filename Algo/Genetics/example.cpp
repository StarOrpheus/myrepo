#include <bits/stdc++.h>

using namespace std;

namespace Genetics
{
    class chromosome;

    class genome
    {
    public:
        vector<chromosome> data;

        genome();
    };

    long long Fitness(genome& gen);
    void mutate(genome& gen);
    genome base_cross(genome &a, genome &b);

    enum SelectionType { TOURNEY, ROULETTE };

    class GeneticEngine
    {
    public:
        int             max_population  = 100;
        int             crossing_cnt    = 100;
        long double     mutation_chance = 0.3;
        int             generation_cnt  = 100;
        SelectionType   selection_type  = TOURNEY;
        vector<genome>  population;

        genome start()
        {
            srand(time(0));

            int         generation   = 0;
            genome      best_genome  = genome();
            long long   best_fitness = Fitness(best_genome);

            while(this->population.size() < this->max_population) {
                this->population.push_back(genome());
            }

            for(int iter = 0; iter < this->generation_cnt && Fitness(best_genome) != 0; iter++)
            {
                vector<genome> new_pop;
                new_pop.reserve(this->crossing_cnt);

                cross(this->population, new_pop);

                for(auto& g: new_pop)
                {
                    long double ch = (rand() % 1000) / (long double) (1000);
                    if(ch <= this->mutation_chance)
                        mutate(g);
                }

                selection(new_pop, this->population);

                for(auto& g: this->population)
                {
                    long long f1 = Fitness(g);
                    if(f1 < best_fitness)
                    {
                        best_fitness = f1;
                        best_genome  = g;
                    }
                }
            }

            return best_genome;
        }

        void cross(vector<genome>& pop, vector<genome>& newpop)
        {
            newpop.clear();
            for(int iter = 0; iter < this->crossing_cnt; iter++)
            {
                int i1 = rand() % pop.size();
                int i2 = rand() % pop.size();

                newpop.push_back(base_cross(pop[i1], pop[i2]));
            }
        }

        void selection(vector<genome> &curpop, vector<genome> &alive)
        {
            alive.clear();
            switch (this->selection_type)
            {
                case TOURNEY:
                    for(int iter = 0; iter < this->max_population; iter++)
                    {
                        int i1 = rand() % curpop.size();
                        int i2 = rand() % curpop.size();
                        while(i2 == i1)
                            i2 = rand() % curpop.size();

                        alive.push_back((Fitness(curpop[i1]) < Fitness(curpop[i2]) ? curpop[i1] : curpop[i2]));
                    }
                    break;

                default:
                    fprintf(stderr, "Unsupported selection metod!");
                    exit(-1);
            }
        }

        GeneticEngine& set_selection(SelectionType st) {this->selection_type = st; return (*this); }
        GeneticEngine& set_generation_cnt(int x) {this->generation_cnt = x; return (*this); }
        GeneticEngine& set_start_population(vector<genome>& res) { this->population = res; return (*this); }
        GeneticEngine& set_max_population(int x) { this->max_population = x; return (*this); }
        GeneticEngine& set_crossing_cnt(int x) { this->crossing_cnt = x; return (*this); }
        GeneticEngine& set_mutation_chance(long double prob) { this->mutation_chance = prob; return (*this); }

        GeneticEngine() {}
    };
}

int a = 5, b = 2, c = 13, m = 44;

class Genetics::chromosome {
public:
    int x;
    chromosome () : x(rand() % 50 * ((rand() & 1) ? -1 : 1)) {}
    chromosome (int x) : x(x) {}
};

Genetics::genome::genome()
{
    data.resize(3);
    for(int i = 0; i < 3; i++)
        data[i] = chromosome();
}

long long Genetics::Fitness(genome &gen)
{
    return abs(gen.data[0].x * a + gen.data[1].x * b + gen.data[2].x * c - m);
}

void Genetics::mutate(Genetics::genome& gen)
{
    int mask = rand() % 8;

    for(int i = 0; i < 3; i++)
        if(mask & (1 << i))
            gen.data[i] = chromosome();
}

Genetics::genome Genetics::base_cross(genome &a, genome &b)
{
    int sep = rand() % 4;
    genome res;

    for(int i = 0; i < sep; i++)
        res.data[i] = a.data[i];
    for(int i = sep; i < 3; i++)
        res.data[i] = b.data[i];

    return res;
}

int main()
{
    Genetics::genome gen = Genetics::GeneticEngine().set_max_population(10).set_generation_cnt(10).set_generation_cnt(50).start();

    for(int i = 0; i < 3; i++)
        cout << gen.data[i].x << " ";
    cout << endl;

    cout << Genetics::Fitness(gen) << endl;
    return 0;
}
