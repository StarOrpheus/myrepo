#include <bits/stdc++.h>

using namespace std;

namespace Genetics
{
    enum SelectionType { DOUBLE_TOURNEY, TRIPLE_TOURNEY, ROULETTE };
    enum MutCondition { COEFFICIENT, PRIORITY };

    class chromosome;

    class genome
    {
    public:
        vector<chromosome> data;

        genome();
    };

    long long   Fitness(genome& gen);
    void        mutate(genome& gen);
    genome      base_cross(genome &a, genome &b);

    class GeneticEngine
    {
    public:
        int             max_population  = 100;
        int             crossing_cnt    = 100;
        int             generation_cnt  = (1<<30);
        long double     mutation_chance = 0.3;
        long double     sum_rfit;
        long long       sum_fit;
        SelectionType   selection_type  = DOUBLE_TOURNEY;
        MutCondition    mut_cond        = PRIORITY;
        vector<genome>  population;

        genome start()
        {
            srand((unsigned int) time(0));

            int         generation   = 0;
            genome      best_genome  = genome();
            long long   best_fitness = Fitness(best_genome);
            this->sum_rfit = 0;

            while(this->population.size() < this->max_population)
                this->population.push_back(genome());

            for(int iter = 0; iter < this->generation_cnt && Fitness(best_genome) != 0; iter++)
            {
#ifdef VERBOSE
                fprintf(stderr, "Generation %d, F(best) =  %lld\n", generation++, best_fitness);
#endif
                vector<genome> new_pop;
                new_pop.reserve((unsigned long) this->crossing_cnt);

                this->sum_rfit = 0;
                this->sum_fit = 0;

                cross(this->population, new_pop);

                for(auto& gen: new_pop)
                    sum_rfit += 1 / (long double) Fitness(gen),
                    sum_fit += 1 / (long double) Fitness(gen);

                for(auto& g: new_pop)
                {
                    long double ch = (rand() % 1000) / (long double) (1000);

                    switch(mut_cond)
                    {
                        case COEFFICIENT:
                            if(ch <= this->mutation_chance)
                                mutate(g);
                            break;
                        case PRIORITY:
                            if(ch <= Fitness(g) / (long double) sum_fit)
                                mutate(g);
                            break;
                    }
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
                int i1 = (int) (rand() % pop.size());
                int i2 = (int) (rand() % pop.size());

                newpop.push_back(base_cross(pop[i1], pop[i2]));
            }
        }

        void selection(vector<genome> &curpop, vector<genome> &alive)
        {
            alive.clear();
            switch (this->selection_type)
            {
            case DOUBLE_TOURNEY:
                for(int iter = 0; iter < this->max_population; iter++)
                {
                    int i1 = (int) (rand() % curpop.size());
                    int i2 = (int) (rand() % curpop.size());
                    while(i2 == i1)
                        i2 = (int) (rand() % curpop.size());

                    alive.push_back((Fitness(curpop[i1]) < Fitness(curpop[i2]) ? curpop[i1] : curpop[i2]));
                }
                break;

            case TRIPLE_TOURNEY:
                for(int iter = 0; iter < this->max_population; iter++)
                {
                    int i1 = (int) (rand() % curpop.size());
                    int i2 = (int) (rand() % curpop.size());
                    int i3 = (int) (rand() % curpop.size());
                    while(i2 == i1)
                        i2 = (int) (rand() % curpop.size());
                    while(i3 == i1 || i3 == i2)
                        i3 = (int) (rand() % curpop.size());

                    auto best = [&](genome& a, genome& b) -> genome& {return (Fitness(a) < Fitness(b) ? a : b); };

                    alive.push_back(best(curpop[i1], best(curpop[i2], curpop[i3])));
                }
                break;

            case ROULETTE:
                sort(curpop.begin(), curpop.end(),
                     [&] (genome& a, genome& b) -> bool { return Fitness(a) < Fitness(b); }
                );
                for(int i = 0; alive.size() < this->max_population; i = (int) ((i + 1) % curpop.size()))
                    if((rand() % 1000) / (long double) (1000) <= 1 / (long double) Fitness(curpop[i]) / this->sum_rfit)
                        alive.push_back(curpop[i]);
                break;

            default:
#ifdef VERBOSE
                fprintf(stderr, "Unsupported selection metod!");
#endif
                exit(-1);
            }
        }

        GeneticEngine& set_mut_condition(MutCondition mt) { this->mut_cond = mt; return (*this); }
        GeneticEngine& set_selection(SelectionType st) { this->selection_type = st; return (*this); }
        GeneticEngine& set_generation_cnt(int x) { this->generation_cnt = x; return (*this); }
        GeneticEngine& set_start_population(vector<genome>& res) { this->population = res; return (*this); }
        GeneticEngine& set_max_population(int x) { this->max_population = x; return (*this); }
        GeneticEngine& set_crossing_cnt(int x) { this->crossing_cnt = x; return (*this); }
        GeneticEngine& set_mutation_chance(long double prob) { this->mutation_chance = prob; return (*this); }

        GeneticEngine() {}
    };
}



int a = 52, b = 21, c = 13, m = 400;

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

int main(int argc, char** argv)
{
    auto t1 = clock();
    Genetics::genome gen = Genetics::GeneticEngine()
            .set_max_population(1000)
            .set_crossing_cnt(1000)
            .start();

    fprintf(stderr, "#%.7LF sec.\n", (clock() - t1) / (long double) CLOCKS_PER_SEC);

    for(int i = 0; i < 3; i++)
        cout << gen.data[i].x << " ";
    cout << endl;

    return 0;
}
