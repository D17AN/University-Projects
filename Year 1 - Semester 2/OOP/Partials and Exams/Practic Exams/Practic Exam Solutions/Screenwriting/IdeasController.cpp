#include "IdeasController.h"

IdeasController::IdeasController(IdeasRepository& _ideasRepo) : ideasRepo{_ideasRepo}{
}

std::vector<Idea> IdeasController::getAll() const
{
	std::vector<Idea> res = this->ideasRepo.getAll();
	std::sort(res.begin(), res.end(), [](const Idea& i1, const Idea& i2){
		return i1.getAct() < i2.getAct();
		});
	return res;
}

std::vector<Idea> IdeasController::getAllAcceptedOfWriter(const std::string& name){
	std::vector<Idea> ideas = this->getAll();
	std::vector<Idea> res;
	std::copy_if(ideas.begin(), ideas.end(), std::back_inserter(res), [&name](const Idea& i){
		return i.getCreator() == name && i.getStatus() == "accepted";
		});
	return res;
}

void IdeasController::addIdea(const Idea& i)
{
	std::string errors = "";
	int act = i.getAct();
	if (i.getDescription() == ""){
		errors += "Description must not be empty!\n";
	}
	if (act != 1 && act != 2 && act != 3){
		errors += "The act must be 1, 2, or 3!\n";
	}

	std::vector<Idea> ideas = this->ideasRepo.getAll();
	auto pos = std::find_if(ideas.begin(), ideas.end(), [&i](const Idea& other){
		return other.getDescription() == i.getDescription() && other.getAct() == i.getAct();
		});

	if (pos != ideas.end()){
		errors += "An idea already exists in the same act with the given description.\n";
	}

	if (errors.size() != 0){
		throw std::exception(errors.c_str());
	}
	
	this->ideasRepo.addIdea(i);
}

void IdeasController::updateIdeaStatus(const Idea& i, const std::string newStatus){
	std::vector<Idea> ideas = this->ideasRepo.getAll();
	auto pos = std::find_if(ideas.begin(), ideas.end(), [&i](const Idea& other){
		return i.getDescription() == other.getDescription() && 
			i.getAct() == other.getAct();
	});

	if (pos == ideas.end()){
		throw std::exception("The idea doesn't exists!");
	}

	int idx = pos - ideas.begin(); // get the relative position by the beginning

	if (ideas[idx].getStatus() != "proposed"){
		throw std::exception("You can only update the status of proposed ideas!");
	}

	this->ideasRepo.updateIdeaStatus(idx, newStatus);
}

void IdeasController::saveToFileAcceptedIdeas(const std::string& fileName){
	std::fstream fout{fileName, std::ios::out | std::ios::trunc};
	std::vector<Idea> ideas = this->getAll(); //ideas sorted by the act
	
	int idx = 0;
	for (int act = 1; act <= 3; act++){
		fout << "Act " << act << ":\n";
		while (idx < ideas.size() && ideas[idx].getAct() == act){
			if (ideas[idx].getStatus() == "accepted"){
				fout << ideas[idx] << "\n";
			}
			idx++;
		}
	}
	fout.close();
}

IdeasController::~IdeasController(){
}
