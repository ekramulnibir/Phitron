or(int i=1; i<=n; i++){
        cout<<"List "<<i<<" : ";
        for(auto j:adj[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }