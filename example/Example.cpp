#include <iostream>
#include "ParticleTree.h"

#include "TRandom2.h"

using namespace std;

int main()
{
	cout << "Hello" << endl;
	TRandom2 *randGen;
	randGen = new TRandom2();
	randGen->SetSeed(0);
	double 	px,py,pz,
			x,y,z,
			dedx, dedx_vtpc1, dedx_vtpc2, dedx_mtpc;

	unsigned int points_size = 8;

	cout << "Creating ParticleTree" << endl;
	ParticleTree particletree("ParticleTree.root");
	cout << "ParticleTree created" << endl;


	cout << "Adding new event" << endl;
	particletree.BeginEvent();

	cout << "Entering particle loop" << endl;
	for(int parts=0; parts<10; parts++)
	{
		cout << "Particle " << parts << endl;
		TNtuple *clusters = new TNtuple("onetuple","onetuple","x:y:z");
		cout << "Tuple created" << endl;

		cout << "Cluster positions for particle " << parts << ":" << endl;
		for(unsigned int i=0; i<points_size;i++)
		{
			x = randGen->Uniform(800);
			y = randGen->Uniform(800);
			z = randGen->Uniform(800);

			cout << "\t" << i << ": (" << x << ", " << y << ", " << z << ")" << endl;

			clusters->Fill(x,y,z);
		}

		px = randGen->Uniform(10);
		py = randGen->Uniform(10);
		pz = randGen->Uniform(10);
		dedx = randGen->Uniform(10);
		dedx_vtpc1 = randGen->Uniform(10);
		dedx_vtpc2 = randGen->Uniform(10);
		dedx_mtpc = randGen->Uniform(10);

		cout << "Momentum for particle " << parts << " : (" << px << ", " << py << ", " << pz << ")" << endl;

		particletree.AddParticle(1,px,py,pz,dedx,dedx_vtpc1,dedx_vtpc2,dedx_mtpc,clusters);
	}
	
	particletree.EndEvent();
	particletree.Close();

	cout << "ParticleTree closed" << endl << "Opening for reading" << endl;

	UInt_t ev, Npa, part;
	TFile *input_rootfile = new TFile("ParticleTree.root");
	TTree* input_tree = (TTree*)input_rootfile->Get("events");
	Event *event_in = new Event();
	Particle *particle;
	input_tree->SetBranchAddress("event",&event_in);
	const Long64_t treeNentries = input_tree->GetEntries();
	for(ev=0; ev<treeNentries; ++ev)
	{
		if(!(ev%5000))
			std::cout << "Event: " << ev << std::endl;

		cout << "Opening event" << endl;
		input_tree->GetEntry(ev);
		Npa = event_in->GetNpa();
		cout << "Npa=" << Npa << endl;

		Float_t clus_x, clus_y, clus_z;

		for(part=0; part<Npa; part++)
		{
			cout << "Opening particle: " << part << endl;
			particle = event_in->GetParticle(part);
			cout << "p=(" << particle->GetPx() << ", " << particle->GetPy() << ", " << particle->GetPz() << ")" << endl;
			TNtuple *tuple = particle->GetClustersPositions();
			tuple->SetBranchAddress("x",&clus_x);
			tuple->SetBranchAddress("y",&clus_y);
			tuple->SetBranchAddress("z",&clus_z);
			for(unsigned int clus=0; clus<tuple->GetEntries(); clus++)
			{
				tuple->GetEntry(clus);
				cout << clus << ": x=" << clus_x << " y=" << clus_y << " z=" << clus_z << endl;
			}
		}
	}

	input_rootfile->Close();
}
