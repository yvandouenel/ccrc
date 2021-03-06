jQuery(function($) {//dom chargé, pas de variables globales, pas de collisions avec d'autres alias

//paramètres de base
var diaporama_width = 311;
var diaporama_height = 260;
var class_text_control = ''; //la classe ".controleur" doit être utilisée
var create_controleur = 1; //création des "controleurs" en chiffres
var over_image = 0; // le résumé apparait au survol de l'image

var class_du_diapo ="#block-views-actualites-accueil-block";
var ul_du_diapo ="#block-views-actualites-accueil-block ul";
var li_du_diapo ="#block-views-actualites-accueil-block ul li.views-row";
var class_du_resume = ".views-field-field-summary-news";
var base_url="";

/*
 * Exmeple de css compatibles avec ce script :
 * Actualités *****************************************************************
 * #block-views-actualites-accueil-block{
 *     float: left;
 *     width: 312px;
 *     height : 265px;
 *     overflow: hidden;
 * }
 * #block-views-actualites-accueil-block ul{
 *     padding: 0;
 *     margin :0;
 *     position:relative;
 * }
 * #block-views-actualites-accueil-block ul li{
 *     list-style: none;
 *     float: left;
 * }
 * #controleurs{
 *     width : 100px;
 *     position : absolute;
 *     top:65px;
 *     left:560px;
 *     width: 50px;
 * }
 * .controleur{
 *     width:25px;
 *     height: 28px;
 *     float : left;
 * }
 */

  if(class_text_control){
       //Création du div contenant les "controleurs"
      jQuery(class_du_diapo).append('<div id="controleurs" style="clear:both;"></div>');

      //dissocier les "controleurs" en les plaçant dans le div "controleurs"
      jQuery(class_text_control).appendTo("#controleurs");

      // Identifier les controleurs et donner la class selected_controleur au premier
      jQuery(class_text_control).each(function(i){
          if(!i) jQuery(this).addClass("selected_controleur");
          jQuery(this).attr('id', 'controleur_'+i);
      });

      //Création des div next et previous
      jQuery(class_du_diapo).append('<div id="previous_diapo"></div>')
      jQuery(class_du_diapo).append('<div id="next_diapo"></div>')
  }


  // Objet diaporama
  function Diaporama(){
      this.nb_diapo = jQuery(li_du_diapo).size();
      this.largeur = diaporama_width;
      this.hauteur = diaporama_height;
      this.largeur_cachee = this.nb_diapo*this.largeur+20; // 20 : marge pour le cas où l'on placerait un contour aux diapos
      this.position_left = 0;
      this.selected_controleur = 0;
      this.urlArray = fullArrayUrl();

      // Méthodes des objets diaporama
      this.next_diapo = next_diapo;
      this.previous_diapo = previous_diapo;
      this.selected_diapo = selected_diapo;
      this.diapo_dimension = diapo_dimension;
      this.add_num_controleur = add_num_controleur;
      this.manage_events = manage_events;
  }

//
// Méthodes des objets diaporama
  function fullArrayUrl(){
      var tableauTransitoire = new Array();
      jQuery(".home_slide_title a").each(function(i){
         tableauTransitoire[i]=jQuery(this).attr("href");
      });
     return tableauTransitoire;
  }
  function diapo_dimension(){
      // dimmensionner le conteneur du diaporama
      jQuery(class_du_diapo).width(this.largeur);
      jQuery(ul_du_diapo).height(this.hauteur);

      //dimmensionner le conteneur de toutes les diapos
      jQuery(ul_du_diapo).width(this.largeur_cachee);
      jQuery(ul_du_diapo).height(this.hauteur);

      // dimmensionner chaque diapo
      jQuery(li_du_diapo).width(this.largeur);//
      jQuery(li_du_diapo).height(this.hauteur);

  }
  function next_diapo(){

      if(this.nb_diapo>this.selected_controleur+1){// ???
          jQuery(ul_du_diapo).animate({"left": "-="+this.largeur+"px"}, "slow");
          this.position_left += this.largeur;
          var id_ncs = this.selected_controleur+1;
          jQuery("#controleur_"+id_ncs).addClass("selected_controleur");
          jQuery("#controleur_"+this.selected_controleur).removeClass("selected_controleur");
          this.selected_controleur = this.selected_controleur+1;

      }else{
          var long_mvt = this.largeur*(this.nb_diapo-1);//alert(long_mvt);
           jQuery(ul_du_diapo).animate({opacity: 0}, 200);
           jQuery(ul_du_diapo).animate({"left": "+="+long_mvt+"px"}, 400,"swing");
           jQuery(ul_du_diapo).animate({opacity: 1}, 200);
           jQuery("#controleur_0").addClass("selected_controleur");
           jQuery("#controleur_"+this.selected_controleur).removeClass("selected_controleur");
           this.selected_controleur =0;
      }
  }
  function previous_diapo(){

       if(this.selected_controleur>0){
          jQuery(ul_du_diapo).animate({"left": "+="+this.largeur+"px"}, "slow");
          this.position_left -= this.largeur;
          var id_ncs = this.selected_controleur-1;
          jQuery("#controleur_"+id_ncs).addClass("selected_controleur");
          jQuery("#controleur_"+this.selected_controleur).removeClass("selected_controleur");
          this.selected_controleur --;
      }else{
          var long_mvt = this.largeur*(this.nb_diapo-1);//alert(long_mvt);
           jQuery(ul_du_diapo).animate({opacity: 0}, 200);
           jQuery(ul_du_diapo).animate({"left": "-="+long_mvt+"px"}, 400,"swing");
           jQuery(ul_du_diapo).animate({opacity: 1}, 200);
           jQuery("#controleur_"+(this.nb_diapo-1)).addClass("selected_controleur");
           jQuery("#controleur_"+this.selected_controleur).removeClass("selected_controleur");
           this.selected_controleur =this.nb_diapo-1;
      }
  }

  function selected_diapo(num_controleur){
      
      var mvt = (this.selected_controleur-num_controleur);
      var long_mvt = Math.abs(mvt)*this.largeur;
      //var id_new_selected = "#controleur"+num_controleur;
      //alert("controleur cliqué : "+num_controleur+" diapo affichée : "+this.selected_controleur+" long_mvt : "+long_mvt+" px");
      if (!mvt) location.href=base_url+this.urlArray[num_controleur];//alert("envoi vers l'url : "+this.urlArray[num_controleur]);
      else if (mvt<0){
          if(Math.abs(mvt)<3) jQuery(ul_du_diapo).animate({"left": "-="+long_mvt+"px"}, "slow");
          else  {
              jQuery(ul_du_diapo).animate({opacity: 0}, 200);
              jQuery(ul_du_diapo).animate({"left": "-="+long_mvt+"px"}, 400,"swing");
              jQuery(ul_du_diapo).animate({opacity: 1}, 200);
          }
          jQuery("#controleur_"+num_controleur).addClass("selected_controleur");
          jQuery("#controleur_"+this.selected_controleur).removeClass("selected_controleur");
          this.selected_controleur -= mvt;      
      }
      else {
          if(Math.abs(mvt)<3) jQuery(ul_du_diapo).animate({"left": "+="+long_mvt+"px"}, "slow");
          else {
              jQuery(ul_du_diapo).animate({opacity: 0}, 200);
              jQuery(ul_du_diapo).animate({"left": "+="+long_mvt+"px"}, 400,"swing");
              jQuery(ul_du_diapo).animate({opacity: 1}, 200);
          }
          jQuery("#controleur_"+num_controleur).addClass("selected_controleur");
          jQuery("#controleur_"+this.selected_controleur).removeClass("selected_controleur");
          this.selected_controleur -= mvt;
      }
  }

  //Création du div contenant les numéros controleurs"controleurs"
  function add_num_controleur(){
      //Création du div contenant les "controleurs"
      jQuery(class_du_diapo).append('<div id="controleurs" style="clear:both;"></div>');
      
      var div_to_add ='';
      for(i=0;i<diapo.nb_diapo; i++){
          if(!i) {div_to_add = '<div id="controleur_'+i+'" class="controleur selected_controleur" style="">'+(i+1)+'</div>';}
          else {div_to_add = '<div id="controleur_'+i+'" style="" class="controleur">'+(i+1)+'</div>';}
          jQuery("#controleurs").append(div_to_add);
      }
  }

  //Gestion des événements
  function manage_events(){
      
      // rendre les controleurs cliquables
     jQuery(".controleur").click(function(event){
          var num_controleur = jQuery(event.target).attr('id');
          num_controleur = num_controleur.substr(num_controleur.length - 1);
          diapo.selected_diapo(num_controleur);
       });


     // rendre les boutons suivants et précédents cliquables
     jQuery("#next_diapo").click(function(event){
          diapo.next_diapo();
       });
       jQuery("#previous_diapo").click(function(event){
          diapo.previous_diapo();
       });

       //Cacher le résumé et rendre les images réactives au survol
       if(over_image){
           jQuery(class_du_resume).hide();
           jQuery(li_du_diapo+" img").mouseover(function(event){
                setTimeout(function(){jQuery(class_du_resume).show();},500);
                setTimeout(function(){jQuery(class_du_resume).animate({"top": "-=214px"}, 400,"swing");},500);
                setTimeout(function(){jQuery(class_du_resume).animate({opacity: 0.8}, 5000);},500);
            });
            jQuery(class_du_resume).mouseleave(function(event){
                jQuery(class_du_resume).hide();
                jQuery(class_du_resume).animate({"top": "+=214px"}, 400,"swing");
                jQuery(class_du_resume).animate({opacity: 1});
            });
       }

    }



  // création de l'instance du diaporama
  diapo = new Diaporama();
  diapo.diapo_dimension();
  if(create_controleur) diapo.add_num_controleur();
  diapo.manage_events();


});// fin du script
 
 

