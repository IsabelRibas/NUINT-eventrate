void make_binnedgraph_mu()
{
    vector<Double_t> vecbinContents; //sm
    vector<Double_t> vecbinContentsBSM_2pi;//criei para cada bsm
    vector<Double_t> vecbinContentsBSM_3pi5;
    vector<Double_t> vecbinContentsBSM_pi;
    vector<Double_t> vecbinContentsBSM_pi5;
    vector<Double_t> vecbinEdges;
    vector<Double_t> vecbinErrors;//sm
    vector<Double_t> vecbinErrorsBSM_2pi;
    vector<Double_t> vecbinErrorsBSM_3pi5;
    vector<Double_t> vecbinErrorsBSM_pi;
    vector<Double_t> vecbinErrorsBSM_pi5;
    //grafico de desaparecimento do neutrino do muon do mutau comparado com o modelo padrão.
    fstream file;//sm
    fstream fileBSM_2pi;
    fstream fileBSM_3pi5;
    fstream fileBSM_pi;
    fstream fileBSM_pi5;
    
    file.open("eventrate_mu.dat",ios::in);
    fileBSM_2pi.open("eventrate_mu_cmutau_1.0e-27_2M_PI.dat",ios::in);
    fileBSM_3pi5.open("eventrate_mu_cmutau_1.0e-27_3M_PI5.dat",ios::in);
    fileBSM_pi.open("eventrate_mu_cmutau_1.0e-27_M_PI.dat",ios::in);
    fileBSM_pi5.open("eventrate_mu_cmutau_1.0e-27_M_PI5.dat",ios::in);
    
    Double_t x,y,res;

    while(x<8)
    {
        file >> x >> y >> res;
        vecbinContents.push_back(y);
        vecbinErrors.push_back(res);
        vecbinEdges.push_back(x);

        fileBSM_2pi >> x >> y >> res;
        vecbinContentsBSM_2pi.push_back(y);
        vecbinErrorsBSM_2pi.push_back(res);
        
        fileBSM_3pi5 >> x >> y >> res;
        vecbinContentsBSM_3pi5.push_back(y);
        vecbinErrorsBSM_3pi5.push_back(res);
        
        fileBSM_pi >> x >> y >> res;
        vecbinContentsBSM_pi.push_back(y);
        vecbinErrorsBSM_pi.push_back(res);
        
        fileBSM_pi5 >> x >> y >> res;
        vecbinContentsBSM_pi5.push_back(y);
        vecbinErrorsBSM_pi5.push_back(res);
        if(file.eof()) break;
    }

    Double_t binContents[vecbinContents.size()];//SM
    Double_t binContentsBSM_2pi[vecbinContentsBSM_2pi.size()];
    Double_t binContentsBSM_3pi5[vecbinContentsBSM_3pi5.size()];
    Double_t binContentsBSM_pi[vecbinContentsBSM_pi.size()];
    Double_t binContentsBSM_pi5[vecbinContentsBSM_pi5.size()];
    Double_t binErrors[vecbinErrors.size()];//sm
    Double_t binErrorsBSM_2pi[vecbinErrorsBSM_2pi.size()];
    Double_t binErrorsBSM_3pi5[vecbinErrorsBSM_3pi5.size()];
    Double_t binErrorsBSM_pi[vecbinErrorsBSM_pi.size()];
    Double_t binErrorsBSM_pi5[vecbinErrorsBSM_pi5.size()];
    Double_t binEdges[vecbinEdges.size()];

    for (size_t i = 0; i < vecbinEdges.size(); ++i) {
        binContents[i] = vecbinContents[i];//sm
        binContentsBSM_2pi[i] = vecbinContentsBSM_2pi[i];
        binContentsBSM_3pi5[i] = vecbinContentsBSM_3pi5[i];
        binContentsBSM_pi[i] = vecbinContentsBSM_pi[i];
        binContentsBSM_pi5[i] = vecbinContentsBSM_pi5[i];
        binErrors[i] = vecbinErrors[i];//sm
        binErrorsBSM_2pi[i] = vecbinErrorsBSM_2pi[i];
        binErrorsBSM_3pi5[i] = vecbinErrorsBSM_3pi5[i];
        binErrorsBSM_pi[i] = vecbinErrorsBSM_pi[i];
        binErrorsBSM_pi5[i] = vecbinErrorsBSM_pi5[i];
        binEdges[i] = vecbinEdges[i];
    }
    
    file.close();
    fileBSM_2pi.close();
    fileBSM_3pi5.close();
    fileBSM_pi.close();
    fileBSM_pi5.close();
    
    int numBins = sizeof(binContents) / sizeof(binContents[0]) - 1;//sm
    int numBinsBSM_2pi = sizeof(binContentsBSM_2pi) / sizeof(binContentsBSM_2pi[0]) - 1;
    int numBinsBSM_3pi5 = sizeof(binContentsBSM_3pi5) / sizeof(binContentsBSM_3pi5[0]) - 1;
    int numBinsBSM_pi = sizeof(binContentsBSM_pi) / sizeof(binContentsBSM_pi[0]) - 1;
    int numBinsBSM_pi5 = sizeof(binContentsBSM_pi5) / sizeof(binContentsBSM_pi5[0]) - 1;

    TH1D *hist    = new TH1D("hist", "Event Rate", numBins,binEdges);//sm
    TH1D *histBSM_2pi = new TH1D("hist", "Event Rate", numBinsBSM_2pi,binEdges);
    TH1D *histBSM_3pi5= new TH1D("hist", "Event Rate", numBinsBSM_3pi5,binEdges);
    TH1D *histBSM_pi = new TH1D("hist", "Event Rate", numBinsBSM_pi,binEdges);
    TH1D *histBSM_pi5 = new TH1D("hist", "Event Rate", numBinsBSM_pi5,binEdges);
    
    for (Int_t i = 0; i < numBins; ++i) {//sm
        hist->SetBinContent(i+1, binContents[i]);
    }
    for (Int_t i = 0; i < numBinsBSM_2pi; ++i) {
        histBSM_2pi->SetBinContent(i+1, binContentsBSM_2pi[i]);
    }
    for (Int_t i = 0; i < numBinsBSM_3pi5; ++i) {
        histBSM_3pi5->SetBinContent(i+1, binContentsBSM_3pi5[i]);
    }
    for (Int_t i = 0; i < numBinsBSM_pi; ++i) {
        histBSM_pi->SetBinContent(i+1, binContentsBSM_pi[i]);
    }
    for (Int_t i = 0; i < numBinsBSM_pi5; ++i) {
        histBSM_pi5->SetBinContent(i+1, binContentsBSM_pi5[i]);
    }

    hist->SetStats(0);//sm
    histBSM_2pi->SetStats(0);
    histBSM_3pi5->SetStats(0);
    histBSM_pi->SetStats(0);
    histBSM_pi5->SetStats(0);


    TCanvas *canvas = new TCanvas("canvas", "Binned Graph", 800, 600);

    canvas->SetGrid();//quadriculado do grafico
    //canvas->SetLogy();

    //título 
    histBSM_2pi->SetTitle("Event rate #times energy in the #nu_{#mu} disappearance channel with c_{#mu#tau}");
    //Definindo cor da linha
    hist->SetLineColor(kBlack);//cor da linha do sm
    histBSM_2pi->SetLineColor(kRed);
    histBSM_3pi5->SetLineColor(kGreen);
    histBSM_pi->SetLineColor(kBlue);
    histBSM_pi5->SetLineColor(6);//cor rosa
    //eixos do gráfico
    //hist->GetXaxis()->SetTitle("Energy");
    //hist->GetYaxis()->SetTitle("Event Rate");
    histBSM_2pi->GetXaxis()->SetTitle("Energy (GeV)");
    histBSM_2pi->GetYaxis()->SetTitle("Event Rate");
    //histBSM_2pi->GetXaxis()->SetLimits(0.20,10.);
    histBSM_2pi->GetXaxis()->SetRangeUser(0,105);
    histBSM_2pi->GetYaxis()->SetRangeUser(0,670);
    //espessura da linha
    hist->SetLineWidth(2);//sm
    histBSM_2pi->SetLineWidth(2);
    histBSM_3pi5->SetLineWidth(2);
    histBSM_pi->SetLineWidth(2);
    histBSM_pi5->SetLineWidth(2);
    //estilo da linha
    hist->SetLineStyle(2);//sm
    histBSM_2pi->SetLineStyle(1);
    histBSM_3pi5->SetLineStyle(1);
    histBSM_pi->SetLineStyle(1);
    histBSM_pi5->SetLineStyle(1);
    //Para centralizar o título
    histBSM_2pi->GetYaxis()->CenterTitle(true);
    histBSM_2pi->GetXaxis()->SetTitleOffset(1.2);
    histBSM_2pi->GetXaxis()->CenterTitle(true);
    histBSM_2pi->GetYaxis()->SetTitleOffset(1.25);
    
    histBSM_2pi->Draw();
    histBSM_3pi5->Draw("same");
    histBSM_pi->Draw("same");
    histBSM_pi5->Draw("same");
    hist->Draw("same");
    //hist->Draw();
    //histBSM->Draw("same");
    //Criando legenda
    TLegend *legend = new TLegend(0.7, 0.7, 0.9, 0.9);
    legend->AddEntry(hist, "Standard", "f");
    legend->AddEntry(histBSM_2pi, "#phi_{#mu#tau} = 0", "f");
    legend->AddEntry(histBSM_3pi5, "#phi_{#mu#tau} = 3#pi/2", "f");
    legend->AddEntry(histBSM_pi, "#phi_{#mu#tau} = #pi", "f");
    legend->AddEntry(histBSM_pi5, "#phi_{#mu#tau} = #pi/2", "f");
    legend->Draw();
    

    //canvas->SaveAs("eventratebingraph_e_StdBSM.png");
    canvas->SaveAs("eventrate_mu_cmutau_1.0e-27_.png");
}
