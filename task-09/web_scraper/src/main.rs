fn main() {
    let response = reqwest::blocking::get(
        "https://crypto.com/price",
    )
    .unwrap()
    .text()
    .unwrap();

    let document = scraper::Html::parse_document(&response);

    let title_selector = scraper::Selector::parse("p.css-rkws3").unwrap();
    let h24vol_selector = scraper::Selector::parse("td.css-1nh9lk8").unwrap();
    let h24ch_selector = scraper::Selector::parse("td>p.chakra-text").unwrap();
    let price_selector = scraper::Selector::parse("td.css-1vyy4qg > div.css-b1ilzc").unwrap();

    let mut name_element = document.select(&title_selector);
    let mut price_element = document.select(&price_selector);
    let mut h24ch_element = document.select(&h24ch_selector);
    let mut h24vol_element = document.select(&h24vol_selector);

    let mut wtr = csv::Writer::from_path("crypto.csv").unwrap();

    wtr.write_record(&["Name","Price","24H Change","24H Volume","Market Cap"]).expect("could not write");

    for _i in 1..51{
        
        let name = name_element.next().unwrap().text().collect::<String>();
        
        let price = price_element.next().unwrap().text().collect::<String>();
        
        let h24ch = h24ch_element.next().unwrap().text().collect::<String>();
        
        let h24vol = h24vol_element.next().unwrap().text().collect::<String>();

        let mcap = h24vol_element.next().unwrap().text().collect::<String>();
        
        wtr.write_record([name,price,h24ch,h24vol,mcap]).expect("could not write");
    }

    wtr.flush().expect("Could not close");
    println!("Done");

}










    