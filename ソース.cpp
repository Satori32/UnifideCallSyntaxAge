#include <iostream>
#include <map>
#include <cstdint>
#include <vector>
#include <memory>

template<class T,class Idx=std::intmax_t>
struct Graph {

	typedef T Type;
	typedef Idx Index;

	template<class U>
	struct  Data
	{
		std::vector<Idx> Node;
		U Data;

		typename std::vector<Idx>::iterator begin() {
			return Node.begin();
		}
		typename std::vector<Idx>::iterator end() {
			return Node.end();
		}
	};
	std::size_t Size() {
		return M->size();
	}
	bool IsArrive(Idx In) {
		return M->find(In) != M->end();
	}

	T& operator [](Idx In) {
		if(IsArrive(In)){ throw std::logic_error(""); }
		return (*M)[In].Data;
	}

	Idx Now = 0;
	typedef std::map<Idx, Data<T>> MAP;
	std::shared_ptr<MAP> M = std::make_shared<MAP>();
};

template<class T,class Idx>
bool Move(Graph<T,Idx>& In, std::size_t P) {
	if (In.IsArrive(P)) {
		for (std::size_t i = 0; i < In.M->at(In.Now).Node.size(); i++) {
			if (In.M->at(In.Now).Node[i] == P) {
				In.Now = P;
				return true;
			}
		}
	}
	return false;
}
template<class T,class I>
T& Get(Graph<T, I>& In) { return In.M->at(In.Now).Data; }

template<class T,class I>
bool Drop(Graph<T, I>& In, I Idx ) { return  In.M->erase(In.M->find(Idx)) == In.M->end(); }

template<class T,class I>
bool Add(Graph<T, I>& In, I N) {
	auto TTT = (*In.M)[N];
	return In.IsArrive(N);
}

int main() {
	Graph<int> G = { 0, };

	bool F= Move(G, 0);//Unifide call syntax age.G.Move(0);

	G[0];

	auto X = Get(G);// G.Get();
	bool Y = Drop<int,std::intmax_t>(G, 0);//G.Drop(0);//why compile error. error solve but duty.
	auto Z = Add<int,std::intmax_t>(G, 128);//G.Add(128);
	return 0;
}