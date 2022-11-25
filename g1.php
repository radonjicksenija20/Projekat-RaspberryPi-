<?php
require '/home/pi/phplot-6.2.0/phplot.php';

$myfile = fopen("data.txt", "r") or die("Unable to open fle!");
$val = array();
$i = 0;
while(!feof($myfile)){
	$val[$i] = fgets($myfile); 
	$i++;
}
#foreach($val as $value){
#	echo("Value is $value ");
#}
$pom0 = (int) $val[0];
$pom1 = (int) $val[1];
$pom2 = (int) $val[2];
$pom3 = (int) $val[3];
$pom4 = (int) $val[4];
fclose($myfile);

$plot = new PHPlot(700, 500);
$title = 'Showing amount of lightness in room through time';
$plot->SetTitle($title);
$plot->SetXTitle('Time[s]');
$plot->SetYTitle('Light');
$plot->SetLegend('y<140 = LOW');
$plot->SetLegend('140<y>200 = MEDIUM');
$plot->SetLegend('y>200 = HIGH');
$data = array(  array('', 0, $pom0), 
		array('', 1, $pom1 ),
		array('', 2, $pom2),
		array('', 3, $pom3),
		array('', 4, $pom4),
		array('', 5, ''),
		array('', 6, ''));
$plot->SetDataValues($data);
$plot->SetDataType('data-data');
$plot->DrawGraph();

?>
