void align(uint32_t freq)
{
    // alignment of the antenna circuit
    // these values are individual for each tuner!
    
    if(freq>=125000)
        DAA = 46;
    else if(freq>=125000)
        DAA = 47;
    else if(freq>=116000)
        DAA = 48;
    else if(freq>=110500)
        DAA = 49;
    else if(freq>=106000)
        DAA = 50;
    else if(freq>=102000)
        DAA = 51;
    else if(freq>=100400)
        DAA = 52;
    else if(freq>=98500)
        DAA = 52;
    else if(freq>=93000)
        DAA = 53;
    else if(freq>=92000)
        DAA = 54;
    else if(freq>=90000)
        DAA = 55;
    else if(freq>=87000)
        DAA = 56;
    else if(freq>=85000)
        DAA = 57;
    else if(freq>=82000)
        DAA = 58;
    else if(freq>=79000)
        DAA = 59;
    else if(freq>=71000)
        DAA = 60;
    else if(freq>=70000)
        DAA = 59;
    else if (freq>=68500)
        DAA = 59;
    else if (freq>=69000)
        DAA = 58;
    else if (freq>=68500)
        DAA = 57;
    else if (freq>=68000)
        DAA = 56;
    else if (freq>=67500)
        DAA = 55;
    else if (freq>=67200)
        DAA = 54;
    else
        DAA = 53;
}
