#ifndef _REPL_ALG_
#define _REPL_ALG_

#include <iostream>
#include <string>
#include <vector>
#include <utility>

//#include "storageUnit.h"

class replAlg{

	public:
		//virtual void readHitUpdate(unsigned module_index) = 0;
		//virtual void replaceUpdate(unsigned module_index) = 0;

		//virtual void updateTable(unsigned module_index) = 0;

		virtual void newEntryUpdate(unsigned module_index) = 0;

		virtual unsigned replace(unsigned module_index) = 0;
			// replace next eviction with module_index, return table index of victim (NOT the module index)

		std::string name_;

		// DEBUG FUNCTIONS //
			virtual void printName(){ std::cout << "\t\t\t\tReplacement: '" << name_ << "'\n"; }

			virtual void printTable(){

				std::cout << "\tPrinting tag table of \"" << name_ << "\".\n";

				for(unsigned i = 0; i < tag_table_.size(); i++)
					std::cout << "\t\t" << i << "\t" << tag_table_[i].second << " <" << tag_table_[i].first << ">\n";
			}


	protected:
		replAlg(std::string name, unsigned max_size) :
			name_(name), max_table_size_(max_size){ }


		virtual unsigned evictNext() = 0; // find location of next table entry to evict (NOT the module index)

		virtual void reorderTable() = 0;

		std::vector< std::pair<int, unsigned> > tag_table_;

		unsigned max_table_size_;
};

#endif
