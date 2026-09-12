/**
 * @file lvpower_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "lvpower_gen.h"

#if defined(LV_USE_XML) && LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void check_font(lv_font_t ** font, const char * name);

/**********************
 *  STATIC VARIABLES
 **********************/

static uint32_t lvpower_target = LVPOWER_TARGET_ALL;

/*----------------
 * Translations
 *----------------*/

#ifndef LV_EDITOR_PREVIEW
    static const char * translation_languages[] = {"en", "pt", "de", "es", "fr", "hu", NULL};
    static const char * translation_tags[] = {"id", "locale", "lvpower", "station", "status", "plugin_start", "or_pair", "ready", "tap_or_scan", "supercharge", "fast", "basic", "connected", "start_charging", "tap_card", "accept_terms", "cable_connected", "ccs_150", "authorize_payment", "charge_150", "charge_80", "charge_overnight", "payment", "welcome_back", "card_ending", "time_left", "supercharge_80", "stop_charging", "power", "energy", "range_added", "cost_so_far", "total_cost", "duration", "energy_delivered", "turbo_complete", "scan_receipt", "unplug_finish", "charged_to_80", "sent_email", "asset_tag", "diagnostics", "station_technician", "safety_interlocks", "thermals", "emergency_stop", "enclosure_panel", "ground_fault", "cable_lock", "ok", "pending", "cable", "power_stage", "service_note", "service_replace", "station_settings", "station_bays", "display_sound", "screen_brightness", "alert_volume", "animations", "enable_transitions", "language", "network_access", "wifi", "scan_docs", "wifi_state", "contactless_payments", "accept_tap", "bay_reserve", "pre_book", "firmware_ver", "up_to_date", "charging_preferences", "session_name", "charge_limit", "stop_level", "off_peak", "charge_peak", "notify_done", "text_80", "save_changes", NULL};
    static const char * translation_texts[] = {
        "en", "pt", "de", "es", "fr", "hu", /* id */
        "English", "Portuguese", "German", "Spanish", "French", "Hungarian", /* locale */
        "LVPOWER", "LVPOWER", "LVPOWER", "LVPOWER", "LVPOWER", "LVPOWER", /* lvpower */
        "Station", "Estação", "Station", "Estación", "Gare", "Állomás", /* station */
        "Status", "Status", "Status", "Estado", "Statut", "Állapot", /* status */
        "Plug in, or scan to start", "Conecte ou faça uma busca para iniciar.", "Anschließen oder scannen, um zu starten", "Conéctalo o escanea para comenzar.", "Branchez ou scannez pour démarrer", "Csatlakoztasd, vagy szkenneld be a kezdéshez", /* plugin_start */
        "or pair with", "ou emparelhar com", "oder kombinieren Sie mit", "o combinar con", "ou associer à", "vagy párosítsa", /* or_pair */
        "Ready", "Preparar", "Bereit", "Listo", "Prêt", "Kész", /* ready */
        "Tap or Scan", "Toque ou escaneie", "Tippen oder Scannen", "Toca o escanea", "Touchez ou scannez", "Koppintson vagy szkenneljen", /* tap_or_scan */
        "SUPERCHARGE", "SUPERCARREGAMENTO", "SUPERLADEN", "SUPERCARGA", "SUPERCHARGE", "SZUPERTÖLTÉS", /* supercharge */
        "FAST", "RÁPIDO", "SCHNELL", "RÁPIDO", "RAPIDE", "GYORS", /* fast */
        "BASIC", "BÁSICO", "BASIC", "BÁSICO", "BASIQUE", "ALAPVETŐ", /* basic */
        "Connected", "Conectado", "Verbunden", "Conectado", "Connecté", "Csatlakoztatva", /* connected */
        "Start charging", "Comece a carregar", "Ladevorgang starten", "Comienza a cargar", "Commencez la charge", "Töltés megkezdése", /* start_charging */
        "Tap your card on the reader", "Aproxime seu cartão do leitor.", "Halten Sie Ihre Karte an das Lesegerät.", "Acerque su tarjeta al lector.", "Approchez votre carte du lecteur", "Érintse a kártyáját az olvasóhoz", /* tap_card */
        "I accept the terms", "Aceito os termos.", "Ich akzeptiere die Bedingungen.", "Acepto los términos", "J'accepte les conditions", "Elfogadom a feltételeket", /* accept_terms */
        "Cable connected", "Cabo conectado", "Kabel angeschlossen", "Cable conectado", "Câble connecté", "Kábel csatlakoztatva", /* cable_connected */
        "CCS · up to 150 kW", "CCS · até 150 kW", "CCS · bis zu 150 kW", "CCS · hasta 150 kW", "CCS · jusqu'à 150 kW", "CCS · akár 150 kW-ig", /* ccs_150 */
        "Authorise payment", "Autorizar pagamento", "Zahlung autorisieren", "Autorizar pago", "Autoriser le paiement", "Fizetés engedélyezése", /* authorize_payment */
        "~150 km in 20 min", "Aproximadamente 150 km em 20 minutos", "~150 km in 20 Minuten", "~150 km en 20 min", "~150 km en 20 min", "~150 km 20 perc alatt", /* charge_150 */
        "~80 km in 20 min", "~80 km em 20 minutos", "~80 km in 20 Minuten", "~80 km en 20 min", "~80 km en 20 min", "~80 km 20 perc alatt", /* charge_80 */
        "Overnight charge", "Cobrança noturna", "Übernachtgebühr", "cargo por pernoctación", "Frais de nuit", "Éjszakai töltés", /* charge_overnight */
        "PAYMENT", "PAGAMENTO", "ZAHLUNG", "PAGO", "PAIEMENT", "FIZETÉS", /* payment */
        "Welcome back", "bem vindo de volta", "Willkommen zurück", "Bienvenido de nuevo", "Content de te revoir", "Üdv ismét", /* welcome_back */
        "Card ending in ····", "Cartão terminando em ····", "Karte endet mit ····", "Tarjeta que termina en ····", "Carte se terminant par ····", "····-ra végződő kártya", /* card_ending */
        "1h 10m left · ready by 12:45", "1h 10m restantes · pronto às 12:45", "Noch 1 Stunde 10 Minuten · fertig um 12:45 Uhr", "Quedan 1 hora y 10 minutos · Listo a las 12:45", "Il reste 1 h 10 min · Prêt à 12 h 45", "1 óra 10 perc van hátra · 12:45-re kész", /* time_left */
        "Supercharging to 80%", "Supercarregando para 80%", "Aufladung auf 80 %", "Supercarga al 80%", "Supercharge à 80 %", "80%-os feltöltés", /* supercharge_80 */
        "Stop charging", "Interrompa o carregamento", "Ladevorgang einstellen", "Deja de cobrar", "Arrêtez la facturation", "Töltés leállítása", /* stop_charging */
        "Power", "Poder", "Leistung", "Fuerza", "Pouvoir", "Hatalom", /* power */
        "Energy", "Energia", "Energie", "Energía", "Énergie", "Energia", /* energy */
        "Range added", "Alcance adicionado", "Reichweite hinzugefügt", "Gama añadida", "Portée ajoutée", "Tartomány hozzáadva", /* range_added */
        "Cost so far", "Custo até o momento", "Bisherige Kosten", "Costo hasta ahora", "Coût jusqu'à présent", "Eddigi költség", /* cost_so_far */
        "Total cost", "Custo total", "Gesamtkosten", "Costo total", "Coût total", "Teljes költség", /* total_cost */
        "Duration", "Duração", "Dauer", "Duración", "Durée", "Időtartam", /* duration */
        "Energy delivered", "Energia fornecida", "Energie geliefert", "Energía suministrada", "Énergie fournie", "Leadott energia", /* energy_delivered */
        "Turbocharge complete", "Carregamento rápido concluído", "Schnellladen abgeschlossen", "Carga rápida completada", "Recharge rapide terminée", "Gyorstöltés befejeződött", /* turbo_complete */
        "Scan for receipt", "Escaneie o código QR para obter o recibo.", "Scannen Sie den Beleg", "Escanee para obtener el recibo.", "Numérisez pour recevoir", "Szkennelés a nyugtáért", /* scan_receipt */
        "Unplug to finish", "Desconecte para finalizar", "Zum Beenden vom Stromnetz trennen.", "Desconectar para terminar", "Débranchez pour terminer", "Húzza ki a konnektorból a befejezéshez", /* unplug_finish */
        "Aurex EX40 · charged to 80%", "Aurex EX40 · carregado até 80%", "Aurex EX40 · auf 80 % geladen", "Aurex EX40 · cargado al 80%", "Aurex EX40 · chargé à 80 %", "Aurex EX40 · 80%-ra feltöltve", /* charged_to_80 */
        "Also sent to lvgl@lvgl.io", "Também enviado para lvgl@lvgl.io", "Ebenfalls gesendet an lvgl@lvgl.io", "También se envió a lvgl@lvgl.io", "Également envoyé à lvgl@lvgl.io", "Elküldve a lvgl@lvgl.io címre is", /* sent_email */
        "ASSET TAG", "ETIQUETA DE ATIVO", "ASSET-TAG", "ETIQUETA DE ACTIVOS", "ÉTIQUETTE D'ACTIF", "ESZKÖZCÍMKE", /* asset_tag */
        "Diagnostics", "Diagnóstico", "Diagnostik", "Diagnóstico", "Diagnostic", "Diagnosztika", /* diagnostics */
        "Station L-04 · Technician session", "Estação L-04 · Sessão técnica", "Station L-04 · Technikersitzung", "Estación L-04 · Sesión técnica", "Station L-04 · Session technique", "L-04 állomás · Technikusi foglalkozás", /* station_technician */
        "SAFETY INTERLOCKS", "INTERTRAVAMENTOS DE SEGURANÇA", "SICHERHEITSVERRIEGELUNGEN", "ENCLAVAMIENTOS DE SEGURIDAD", "VERROUILLAGES DE SÉCURITÉ", "BIZTONSÁGI RETESZEK", /* safety_interlocks */
        "THERMALS", "TÉRMICOS", "Wärmelampen", "TÉRMICAS", "THERMIQUES", "TERMALOK", /* thermals */
        "Emergency stop released", "Parada de emergência liberada", "Not-Aus-Schalter gelöst", "Se ha liberado la parada de emergencia.", "Arrêt d'urgence relâché", "Vészleállító kioldva", /* emergency_stop */
        "Enclosure panel closed", "Painel de fechamento", "Gehäuseklappe geschlossen", "Panel de la carcasa cerrado", "Panneau du boîtier fermé", "Zárt burkolatpanel", /* enclosure_panel */
        "Ground-fault monitor clear", "Monitor de falha de aterramento desativado", "Erdschlussüberwachung gelöscht", "Monitor de falla a tierra vacío", "Surveillance des défauts à la terre claire", "Földzárlatvédelmi monitor törlése", /* ground_fault */
        "Cable lock engaged", "Cadeado de cabo acionado", "Kabelschloss eingerastet", "Bloqueo de cable activado", "Verrou de câble activé", "Kábelzár be van kapcsolva", /* cable_lock */
        "OK", "OK", "OK", "DE ACUERDO", "D'ACCORD", "RENDBEN", /* ok */
        "Pending", "Pendente", "Ausstehend", "Pendiente", "En attente", "Függőben levő", /* pending */
        "Cable", "Cabo", "Kabel", "Cable", "Câble", "Kábel", /* cable */
        "Power stage", "Estágio de potência", "Leistungsstufe", "Etapa de potencia", "Phase de puissance", "Teljesítményfokozat", /* power_stage */
        "SERVICE NOTE", "NOTA DE SERVIÇO", "Servicehinweis", "NOTA DE SERVICIO", "NOTE DE SERVICE", "SZERVIZMEGJEGYZÉS", /* service_note */
        "Replaced RFID reader module on bay L-04. Connector lock intermittent - monitoring. Next PM due 2026-08-15.", "Substituído o módulo leitor RFID no compartimento L-04. Trava do conector intermitente - em monitoramento. Próxima manutenção preventiva prevista para 15/08/2026.", "RFID-Lesegerät in Steckplatz L-04 ausgetauscht. Steckerverriegelung funktioniert zeitweise nicht – wird überwacht. Nächste Wartung fällig am 15.08.2026.", "Se sustituyó el módulo lector RFID en la bahía L-04. El bloqueo del conector presenta fallos intermitentes; se está monitorizando. El próximo mantenimiento preventivo está previsto para el 15 de agosto de 2026.", "Module lecteur RFID remplacé dans la baie L-04. Verrouillage intermittent du connecteur - surveillance. Prochaine maintenance préventive prévue le 15/08/2026.", "RFID olvasó modul csere az L-04-es rekeszben. Csatlakozózár szakaszos - felügyelet. Következő délutáni beküldési határidő: 2026-08-15.", /* service_replace */
        "Station settings", "Configurações da estação", "Stationseinstellungen", "Configuración de la estación", "Paramètres de la station", "Állomásbeállítások", /* station_settings */
        "Station L-04 · 6 bays", "Estação L-04 · 6 baias", "Bahnhof L-04 · 6 Stellplätze", "Estación L-04 · 6 bahías", "Station L-04 · 6 travées", "L-04 állomás · 6 állás", /* station_bays */
        "DISPLAY & SOUND", "EXIBIÇÃO E SOM", "ANZEIGE & TON", "PANTALLA Y SONIDO", "AFFICHAGE ET SON", "KIJELZŐ ÉS HANG", /* display_sound */
        "Screen brightness", "Brilho da tela", "Bildschirmhelligkeit", "brillo de la pantalla", "Luminosité de l'écran", "Képernyő fényereje", /* screen_brightness */
        "Alert volume", "Volume de alerta", "Alarmlautstärke", "Volumen de alerta", "Volume d'alerte", "Riasztás hangereje", /* alert_volume */
        "Animations", "Animações", "Animationen", "Animaciones", "Animations", "Animációk", /* animations */
        "Enable transitions", "Ativar transições", "Übergänge aktivieren", "Habilitar transiciones", "Activer les transitions", "Átmenetek engedélyezése", /* enable_transitions */
        "LANGUAGE", "LINGUAGEM", "SPRACHE", "IDIOMA", "LANGUE", "NYELV", /* language */
        "NETWORK & ACCESS", "REDE E ACESSO", "NETZWERK & ZUGANG", "RED Y ACCESO", "RÉSEAU ET ACCÈS", "HÁLÓZAT ÉS HOZZÁFÉRÉS", /* network_access */
        "Wi-Fi", "Wi-fi", "W-lan", "Wi-Fi", "Wi-Fi", "Wi-Fi", /* wifi */
        "Scan for maintenance docs", "Digitalize para obter documentos de manutenção.", "Nach Wartungsdokumenten suchen", "Escanee en busca de documentos de mantenimiento.", "Rechercher les documents de maintenance", "Karbantartási dokumentációk beolvasása", /* scan_docs */
        "Levland-Ops · connected", "Levland-Ops · conectado", "Levland-Ops · verbunden", "Levland-Ops · conectado", "Levland-Ops · connecté", "Levland-Ops · csatlakoztatva", /* wifi_state */
        "Contactless payments", "pagamentos sem contato", "Kontaktloses Bezahlen", "Pagos sin contacto", "paiements sans contact", "Érintésmentes fizetések", /* contactless_payments */
        "Accept tap-to-pay", "Aceite pagamentos por aproximação", "Akzeptieren Sie kontaktloses Bezahlen.", "Aceptamos pagos sin contacto.", "Acceptez le paiement sans contact", "Érintéses fizetés elfogadása", /* accept_tap */
        "Bay reservations", "Reservas na baía", "Buchtreservierungen", "Reservas de la bahía", "Réservations de la baie", "Öböl-rezervátumok", /* bay_reserve */
        "Allow drivers to pre-book", "Permitir que os motoristas façam reservas antecipadas", "Ermöglichen Sie es Fahrern, im Voraus zu buchen", "Permitir que los conductores reserven con antelación.", "Autoriser les chauffeurs à réserver à l'avance", "Engedélyezze a sofőröknek az előzetes foglalást", /* pre_book */
        "Firmware v3.2.1", "Firmware v3.2.1", "Firmware v3.2.1", "Firmware v3.2.1", "Firmware v3.2.1", "Firmware v3.2.1", /* firmware_ver */
        "· up to date", "· atualizado", "• auf dem neuesten Stand", "· A hoy", "· à jour", "· naprakész", /* up_to_date */
        "Charging preferences", "Preferências de carregamento", "Ladeeinstellungen", "preferencias de carga", "préférences de facturation", "Töltési beállítások", /* charging_preferences */
        "Aurex EX40 · adjust this session", "Aurex EX40 · ajustar esta sessão", "Aurex EX40 · diese Sitzung anpassen", "Aurex EX40 · ajustar esta sesión", "Aurex EX40 · ajuster cette session", "Aurex EX40 · módosítsa ezt a munkamenetet", /* session_name */
        "Charge limit", "Limite de cobrança", "Ladelimit", "Límite de cargo", "Limite de charge", "Díjkorlát", /* charge_limit */
        "Stop when the battery reaches this level", "Pare quando a bateria atingir este nível.", "Stoppen Sie, sobald der Akku diesen Ladestand erreicht hat.", "Deténgase cuando la batería alcance este nivel.", "Arrêtez-vous lorsque la batterie atteint ce niveau.", "Állj meg, amikor az akkumulátor eléri ezt a szintet", /* stop_level */
        "Off-peak only", "Somente fora do horário de pico", "Nur außerhalb der Spitzenzeiten", "Solo en horas valle", "Hors pointe uniquement", "Csak csúcsidőn kívül", /* off_peak */
        "Charge during cheaper hours", "Carregue durante os horários mais baratos.", "Laden Sie während der günstigeren Stunden.", "Cobrar durante las horas más económicas.", "Rechargez pendant les heures creuses.", "Díjszabás olcsóbb órákban", /* charge_peak */
        "Notify when done", "Avise quando terminar", "Benachrichtigen Sie mich, sobald es erledigt ist.", "Notificar cuando haya terminado", "Prévenez-moi quand ce sera fait", "Értesítsen, ha kész", /* notify_done */
        "Text me at 80%", "Envie-me uma mensagem quando estiver a 80%", "Schreib mir eine SMS bei 80%", "Envíame un mensaje de texto al 80%.", "Envoie-moi un SMS à 80%", "Írj SMS-t 80%-nál", /* text_80 */
        "Save changes", "Salvar alterações", "Änderungen speichern", "Guardar cambios", "Enregistrer les modifications", "Változtatások mentése", /* save_changes */
    };
#endif

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * font_gabarito_semibold_32;
extern lv_font_t font_gabarito_semibold_32_data;
lv_font_t * font_gabarito_semibold_22;
extern lv_font_t font_gabarito_semibold_22_data;
lv_font_t * font_gabarito_regular_15;
extern lv_font_t font_gabarito_regular_15_data;
lv_font_t * font_gabarito_semibold_15;
extern lv_font_t font_gabarito_semibold_15_data;
lv_font_t * font_gabarito_medium_13;
extern lv_font_t font_gabarito_medium_13_data;
lv_font_t * font_gabarito_regular_12;
extern lv_font_t font_gabarito_regular_12_data;
lv_font_t * font_gabarito_medium_11;
extern lv_font_t font_gabarito_medium_11_data;
lv_font_t * font_gabarito_semibold_34;
extern lv_font_t font_gabarito_semibold_34_data;
lv_font_t * font_gabarito_semibold_26;
extern lv_font_t font_gabarito_semibold_26_data;
lv_font_t * font_gabarito_bold_132;
extern lv_font_t font_gabarito_bold_132_data;
lv_font_t * font_gabarito_medium_44;
extern lv_font_t font_gabarito_medium_44_data;
lv_font_t * font_gabarito_semibold_18;
extern lv_font_t font_gabarito_semibold_18_data;
lv_font_t * font_gabarito_semibold_24;
extern lv_font_t font_gabarito_semibold_24_data;
lv_font_t * font_gabarito_semibold_20;
extern lv_font_t font_gabarito_semibold_20_data;
lv_font_t * font_gabarito_medium_15;
extern lv_font_t font_gabarito_medium_15_data;
lv_font_t * font_gabarito_regular_13;
extern lv_font_t font_gabarito_regular_13_data;
lv_font_t * font_gabarito_medium_12;
extern lv_font_t font_gabarito_medium_12_data;
lv_font_t * font_gabarito_regular_11;
extern lv_font_t font_gabarito_regular_11_data;
lv_font_t * font_inter_bold_86;
extern lv_font_t font_inter_bold_86_data;
lv_font_t * font_inter_semi_bold_41;
extern lv_font_t font_inter_semi_bold_41_data;
lv_font_t * font_inter_semi_bold_38;
extern lv_font_t font_inter_semi_bold_38_data;
lv_font_t * font_inter_semi_bold_30;
extern lv_font_t font_inter_semi_bold_30_data;
lv_font_t * font_inter_semi_bold_13;
extern lv_font_t font_inter_semi_bold_13_data;
lv_font_t * font_inter_bold_46;
extern lv_font_t font_inter_bold_46_data;
lv_font_t * font_inter_regular_20;
extern lv_font_t font_inter_regular_20_data;
lv_font_t * font_inter_medium_15;
extern lv_font_t font_inter_medium_15_data;
lv_font_t * font_inter_semi_bold_15;
extern lv_font_t font_inter_semi_bold_15_data;
lv_font_t * font_inter_bold_14;
extern lv_font_t font_inter_bold_14_data;
lv_font_t * font_inter_semi_bold_12;
extern lv_font_t font_inter_semi_bold_12_data;
lv_font_t * font_inter_semi_bold_21;
extern lv_font_t font_inter_semi_bold_21_data;
lv_font_t * font_inter_regular_15;
extern lv_font_t font_inter_regular_15_data;
lv_font_t * font_inter_medium_12;
extern lv_font_t font_inter_medium_12_data;
lv_font_t * font_inter_bold_11;
extern lv_font_t font_inter_bold_11_data;
lv_font_t * font_inter_semi_bold_10;
extern lv_font_t font_inter_semi_bold_10_data;
lv_font_t * font_inter_regular_12_5;
extern lv_font_t font_inter_regular_12_5_data;
lv_font_t * font_gabarito_semibold_19_200000762939453;
extern lv_font_t font_gabarito_semibold_19_200000762939453_data;
lv_font_t * font_gabarito_semibold_43_52000427246094;
extern lv_font_t font_gabarito_semibold_43_52000427246094_data;
lv_font_t * font_gabarito_regular_19_200000762939453;
extern lv_font_t font_gabarito_regular_19_200000762939453_data;
lv_font_t * font_gabarito_regular_15_360000610351562;
extern lv_font_t font_gabarito_regular_15_360000610351562_data;
lv_font_t * font_gabarito_semibold_28_160001754760742;
extern lv_font_t font_gabarito_semibold_28_160001754760742_data;
lv_font_t * font_gabarito_regular_16_64000129699707;
extern lv_font_t font_gabarito_regular_16_64000129699707_data;
lv_font_t * font_gabarito_medium_19_200000762939453;
extern lv_font_t font_gabarito_medium_19_200000762939453_data;
lv_font_t * font_gabarito_medium_15_360000610351562;
extern lv_font_t font_gabarito_medium_15_360000610351562_data;
lv_font_t * font_gabarito_semibold_24_57600212097168;
extern lv_font_t font_gabarito_semibold_24_57600212097168_data;
lv_font_t * font_gabarito_regular_24_57600212097168;
extern lv_font_t font_gabarito_regular_24_57600212097168_data;
lv_font_t * font_gabarito_medium_21_299203872680664;
extern lv_font_t font_gabarito_medium_21_299203872680664_data;
lv_font_t * font_gabarito_semibold_36_044803619384766;
extern lv_font_t font_gabarito_semibold_36_044803619384766_data;
lv_font_t * font_gabarito_semibold_40_96000289916992;
extern lv_font_t font_gabarito_semibold_40_96000289916992_data;
lv_font_t * font_gabarito_semibold_33_28000259399414;
extern lv_font_t font_gabarito_semibold_33_28000259399414_data;
lv_font_t * font_gabarito_semibold_23_040000915527344;
extern lv_font_t font_gabarito_semibold_23_040000915527344_data;
lv_font_t * font_gabarito_semibold_40_959999084472656;
extern lv_font_t font_gabarito_semibold_40_959999084472656_data;
lv_font_t * font_gabarito_regular_19_19999885559082;
extern lv_font_t font_gabarito_regular_19_19999885559082_data;
lv_font_t * font_gabarito_semibold_19_19999885559082;
extern lv_font_t font_gabarito_semibold_19_19999885559082_data;
lv_font_t * font_gabarito_regular_15_359999656677246;
extern lv_font_t font_gabarito_regular_15_359999656677246_data;
lv_font_t * font_gabarito_semibold_33_279998779296875;
extern lv_font_t font_gabarito_semibold_33_279998779296875_data;
lv_font_t * font_gabarito_semibold_28_15999984741211;
extern lv_font_t font_gabarito_semibold_28_15999984741211_data;
lv_font_t * font_gabarito_semibold_43_52000045776367;
extern lv_font_t font_gabarito_semibold_43_52000045776367_data;
lv_font_t * font_gabarito_medium_14_079999923706055;
extern lv_font_t font_gabarito_medium_14_079999923706055_data;
lv_font_t * font_gabarito_semibold_24_576000213623047;
extern lv_font_t font_gabarito_semibold_24_576000213623047_data;
lv_font_t * font_gabarito_regular_24_576000213623047;
extern lv_font_t font_gabarito_regular_24_576000213623047_data;
lv_font_t * font_gabarito_medium_21_29920196533203;
extern lv_font_t font_gabarito_medium_21_29920196533203_data;
lv_font_t * font_gabarito_semibold_36_0447998046875;
extern lv_font_t font_gabarito_semibold_36_0447998046875_data;
lv_font_t * font_gabarito_bold_168_95999145507812;
extern lv_font_t font_gabarito_bold_168_95999145507812_data;
lv_font_t * font_gabarito_medium_56_31999969482422;
extern lv_font_t font_gabarito_medium_56_31999969482422_data;
lv_font_t * font_gabarito_semibold_23_03999900817871;
extern lv_font_t font_gabarito_semibold_23_03999900817871_data;
lv_font_t * font_gabarito_semibold_30_719999313354492;
extern lv_font_t font_gabarito_semibold_30_719999313354492_data;
lv_font_t * font_gabarito_regular_16_639999389648438;
extern lv_font_t font_gabarito_regular_16_639999389648438_data;
lv_font_t * font_gabarito_regular_14_079999923706055;
extern lv_font_t font_gabarito_regular_14_079999923706055_data;
lv_font_t * font_gabarito_medium_16_639999389648438;
extern lv_font_t font_gabarito_medium_16_639999389648438_data;
lv_font_t * font_gabarito_semibold_25_599998474121094;
extern lv_font_t font_gabarito_semibold_25_599998474121094_data;
lv_font_t * font_gabarito_medium_19_19999885559082;
extern lv_font_t font_gabarito_medium_19_19999885559082_data;
lv_font_t * font_gabarito_medium_15_359999656677246;
extern lv_font_t font_gabarito_medium_15_359999656677246_data;
lv_font_t * font_gabarito_medium_16_64000129699707;
extern lv_font_t font_gabarito_medium_16_64000129699707_data;

/*----------------
 * Images
 *----------------*/

/* Targets: any */
const void * image_qr_receipt_115x115 = NULL;
extern const void * image_qr_receipt_115x115_data;
const void * image_qr_receipt_64x64 = NULL;
extern const void * image_qr_receipt_64x64_data;
const void * image_plug_large = NULL;
extern const void * image_plug_large_data;
const void * image_back_byd_1039x365 = NULL;
extern const void * image_back_byd_1039x365_data;
const void * image_back_byd_755x265 = NULL;
extern const void * image_back_byd_755x265_data;
const void * image_back_byd_425x149 = NULL;
extern const void * image_back_byd_425x149_data;
const void * image_4 = NULL;
extern const void * image_4_data;
const void * image_front_byd = NULL;
extern const void * image_front_byd_data;
const void * image_icon_supercharge_green_24419 = NULL;
extern const void * image_icon_supercharge_green_24419_data;
const void * image_icon_zap_19913 = NULL;
extern const void * image_icon_zap_19913_data;
const void * image_icon_plug_19916 = NULL;
extern const void * image_icon_plug_19916_data;
const void * image_icon_supercharge = NULL;
extern const void * image_icon_supercharge_data;
const void * image_icon_nfc_19919 = NULL;
extern const void * image_icon_nfc_19919_data;
const void * image_vec_263_32 = NULL;
extern const void * image_vec_263_32_data;
const void * image_icon_diagnostic_323653 = NULL;
extern const void * image_icon_diagnostic_323653_data;
const void * image_icon_settings_1988 = NULL;
extern const void * image_icon_settings_1988_data;
const void * image_vec_263_263 = NULL;
extern const void * image_vec_263_263_data;
const void * image_icon_back_323661 = NULL;
extern const void * image_icon_back_323661_data;
const void * image_icon_close_30435 = NULL;
extern const void * image_icon_close_30435_data;
const void * image_vec_270_4 = NULL;
extern const void * image_vec_270_4_data;
const void * image_vec_270_5 = NULL;
extern const void * image_vec_270_5_data;
const void * image_vec_270_6 = NULL;
extern const void * image_vec_270_6_data;
const void * image_vec_270_7 = NULL;
extern const void * image_vec_270_7_data;
const void * image_vec_270_8 = NULL;
extern const void * image_vec_270_8_data;
const void * image_lucide_nfc = NULL;
extern const void * image_lucide_nfc_data;
const void * image_vec_273_184 = NULL;
extern const void * image_vec_273_184_data;
const void * image_vec_273_185 = NULL;
extern const void * image_vec_273_185_data;
const void * image_vec_273_186 = NULL;
extern const void * image_vec_273_186_data;
const void * image_vec_328_444 = NULL;
extern const void * image_vec_328_444_data;
const void * img_wheel_base = NULL;
extern const void * img_wheel_base_data;
const void * img_wheel_rim = NULL;
extern const void * img_wheel_rim_data;
const void * img_wheel_base_98 = NULL;
extern const void * img_wheel_base_98_data;
const void * img_wheel_rim_98 = NULL;
extern const void * img_wheel_rim_98_data;

/*----------------
 * Global styles
 *----------------*/

lv_style_t style_heading_global;
lv_style_t style_font_title_global;
lv_style_t style_body_global;
lv_style_t style_body_strong_global;
lv_style_t style_chip_global;
lv_style_t style_caption_global;
lv_style_t style_overline_global;
lv_style_t style_stat_lg_global;
lv_style_t style_stat_md_global;
lv_style_t style_hero_global;
lv_style_t style_hero_unit_global;
lv_style_t style_font_subtitle_global;
lv_style_t style_stat_sm_global;
lv_style_t style_stat_xs_global;
lv_style_t style_font_label_global;
lv_style_t style_font_meta_global;
lv_style_t style_badge_global;
lv_style_t style_micro_global;
lv_style_t style_shadow_card_global;
lv_style_t style_shadow_modal_global;
lv_style_t style_shadow_knob_global;
lv_style_t style_screen_base_global;
lv_style_t style_bar_b_danger_global;
lv_style_t style_bar_b_green_global;
lv_style_t style_bar_b_warn_global;
lv_style_t style_chip_card_dot_green_global;
lv_style_t style_chip_card_dot_grey_global;
lv_style_t style_chip_card_dot_red_global;
lv_style_t style_chip_card_green_global;
lv_style_t style_chip_card_grey_global;
lv_style_t style_chip_card_label_green_global;
lv_style_t style_chip_card_label_grey_global;
lv_style_t style_chip_card_label_red_global;
lv_style_t style_chip_card_red_global;
lv_style_t style_chip_header_green_global;
lv_style_t style_chip_header_grey_global;
lv_style_t style_chip_header_orange_global;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t subject_alert_volume;
lv_subject_t subject_bay_reserve;
lv_subject_t subject_cable_thermal;
lv_subject_t subject_card_ending;
lv_subject_t subject_chg_limit;
lv_subject_t subject_chg_pct;
lv_subject_t subject_contactless;
lv_subject_t subject_current_cost;
lv_subject_t subject_km_added;
lv_subject_t subject_power_stage;
lv_subject_t subject_preferences_modal_state;
lv_subject_t subject_screen_brightness;
lv_subject_t subject_time;
lv_subject_t subject_wifi;
lv_subject_t subject_unbound_card_bay_bar;
lv_subject_t subject_unbound_card_bay_value_card_bay_2;
lv_subject_t subject_unbound_field_slider_control_slider;
lv_subject_t subject_unbound_field_slider_value_field_slider_2;
lv_subject_t subject_unbound_row_toggle_control_switch;
lv_subject_t subject_unbound_tile_stat_value_tile_stat_2;
lv_subject_t subject_language_id;
lv_subject_t subject_animations;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lvpower_init_gen(const char * asset_path)
{
    /* When running from the editor the theme set from the XML should overwrite this */
#if !defined(LV_EDITOR_PREVIEW)
#if LV_USE_THEME_SIMPLE
    lv_display_t * disp = lv_display_get_default();
    lv_theme_t * th = lv_theme_simple_init(disp);
    lv_display_set_theme(disp, th);
#else
    LV_LOG_WARN("Simple theme is selected in project.xml but LV_USE_THEME_SIMPLE is disabled");
#endif
#endif /*LV_EDITOR_PREVIEW*/


    /*----------------
     * Fonts
     *----------------*/

    /* Targets: any */

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        if (!font_gabarito_semibold_32) {
            /* font_gabarito_semibold_32 */
            /* get font 'font_gabarito_semibold_32' from a C array */
            font_gabarito_semibold_32 = &font_gabarito_semibold_32_data;

        }
        if (!font_gabarito_semibold_22) {
            /* font_gabarito_semibold_22 */
            /* get font 'font_gabarito_semibold_22' from a C array */
            font_gabarito_semibold_22 = &font_gabarito_semibold_22_data;

        }
        if (!font_gabarito_regular_15) {
            /* font_gabarito_regular_15 */
            /* get font 'font_gabarito_regular_15' from a C array */
            font_gabarito_regular_15 = &font_gabarito_regular_15_data;

        }
        if (!font_gabarito_semibold_15) {
            /* font_gabarito_semibold_15 */
            /* get font 'font_gabarito_semibold_15' from a C array */
            font_gabarito_semibold_15 = &font_gabarito_semibold_15_data;

        }
        if (!font_gabarito_medium_13) {
            /* font_gabarito_medium_13 */
            /* get font 'font_gabarito_medium_13' from a C array */
            font_gabarito_medium_13 = &font_gabarito_medium_13_data;

        }
        if (!font_gabarito_regular_12) {
            /* font_gabarito_regular_12 */
            /* get font 'font_gabarito_regular_12' from a C array */
            font_gabarito_regular_12 = &font_gabarito_regular_12_data;

        }
        if (!font_gabarito_medium_11) {
            /* font_gabarito_medium_11 */
            /* get font 'font_gabarito_medium_11' from a C array */
            font_gabarito_medium_11 = &font_gabarito_medium_11_data;

        }
        if (!font_gabarito_semibold_34) {
            /* font_gabarito_semibold_34 */
            /* get font 'font_gabarito_semibold_34' from a C array */
            font_gabarito_semibold_34 = &font_gabarito_semibold_34_data;

        }
        if (!font_gabarito_semibold_26) {
            /* font_gabarito_semibold_26 */
            /* get font 'font_gabarito_semibold_26' from a C array */
            font_gabarito_semibold_26 = &font_gabarito_semibold_26_data;

        }
        if (!font_gabarito_bold_132) {
            /* font_gabarito_bold_132 */
            /* get font 'font_gabarito_bold_132' from a C array */
            font_gabarito_bold_132 = &font_gabarito_bold_132_data;

        }
        if (!font_gabarito_medium_44) {
            /* font_gabarito_medium_44 */
            /* get font 'font_gabarito_medium_44' from a C array */
            font_gabarito_medium_44 = &font_gabarito_medium_44_data;

        }
        if (!font_gabarito_semibold_18) {
            /* font_gabarito_semibold_18 */
            /* get font 'font_gabarito_semibold_18' from a C array */
            font_gabarito_semibold_18 = &font_gabarito_semibold_18_data;

        }
        if (!font_gabarito_semibold_24) {
            /* font_gabarito_semibold_24 */
            /* get font 'font_gabarito_semibold_24' from a C array */
            font_gabarito_semibold_24 = &font_gabarito_semibold_24_data;

        }
        if (!font_gabarito_semibold_20) {
            /* font_gabarito_semibold_20 */
            /* get font 'font_gabarito_semibold_20' from a C array */
            font_gabarito_semibold_20 = &font_gabarito_semibold_20_data;

        }
        if (!font_gabarito_medium_15) {
            /* font_gabarito_medium_15 */
            /* get font 'font_gabarito_medium_15' from a C array */
            font_gabarito_medium_15 = &font_gabarito_medium_15_data;

        }
        if (!font_gabarito_regular_13) {
            /* font_gabarito_regular_13 */
            /* get font 'font_gabarito_regular_13' from a C array */
            font_gabarito_regular_13 = &font_gabarito_regular_13_data;

        }
        if (!font_gabarito_medium_12) {
            /* font_gabarito_medium_12 */
            /* get font 'font_gabarito_medium_12' from a C array */
            font_gabarito_medium_12 = &font_gabarito_medium_12_data;

        }
        if (!font_gabarito_regular_11) {
            /* font_gabarito_regular_11 */
            /* get font 'font_gabarito_regular_11' from a C array */
            font_gabarito_regular_11 = &font_gabarito_regular_11_data;

        }
        if (!font_inter_bold_86) {
            /* font_inter_bold_86 */
            /* get font 'font_inter_bold_86' from a C array */
            font_inter_bold_86 = &font_inter_bold_86_data;

        }
        if (!font_inter_semi_bold_41) {
            /* font_inter_semi_bold_41 */
            /* get font 'font_inter_semi_bold_41' from a C array */
            font_inter_semi_bold_41 = &font_inter_semi_bold_41_data;

        }
        if (!font_inter_semi_bold_38) {
            /* font_inter_semi_bold_38 */
            /* get font 'font_inter_semi_bold_38' from a C array */
            font_inter_semi_bold_38 = &font_inter_semi_bold_38_data;

        }
        if (!font_inter_semi_bold_30) {
            /* font_inter_semi_bold_30 */
            /* get font 'font_inter_semi_bold_30' from a C array */
            font_inter_semi_bold_30 = &font_inter_semi_bold_30_data;

        }
        if (!font_inter_semi_bold_13) {
            /* font_inter_semi_bold_13 */
            /* get font 'font_inter_semi_bold_13' from a C array */
            font_inter_semi_bold_13 = &font_inter_semi_bold_13_data;

        }
        if (!font_inter_bold_46) {
            /* font_inter_bold_46 */
            /* get font 'font_inter_bold_46' from a C array */
            font_inter_bold_46 = &font_inter_bold_46_data;

        }
        if (!font_inter_regular_20) {
            /* font_inter_regular_20 */
            /* get font 'font_inter_regular_20' from a C array */
            font_inter_regular_20 = &font_inter_regular_20_data;

        }
        if (!font_inter_medium_15) {
            /* font_inter_medium_15 */
            /* get font 'font_inter_medium_15' from a C array */
            font_inter_medium_15 = &font_inter_medium_15_data;

        }
        if (!font_inter_semi_bold_15) {
            /* font_inter_semi_bold_15 */
            /* get font 'font_inter_semi_bold_15' from a C array */
            font_inter_semi_bold_15 = &font_inter_semi_bold_15_data;

        }
        if (!font_inter_bold_14) {
            /* font_inter_bold_14 */
            /* get font 'font_inter_bold_14' from a C array */
            font_inter_bold_14 = &font_inter_bold_14_data;

        }
        if (!font_inter_semi_bold_12) {
            /* font_inter_semi_bold_12 */
            /* get font 'font_inter_semi_bold_12' from a C array */
            font_inter_semi_bold_12 = &font_inter_semi_bold_12_data;

        }
        if (!font_inter_semi_bold_21) {
            /* font_inter_semi_bold_21 */
            /* get font 'font_inter_semi_bold_21' from a C array */
            font_inter_semi_bold_21 = &font_inter_semi_bold_21_data;

        }
        if (!font_inter_regular_15) {
            /* font_inter_regular_15 */
            /* get font 'font_inter_regular_15' from a C array */
            font_inter_regular_15 = &font_inter_regular_15_data;

        }
        if (!font_inter_medium_12) {
            /* font_inter_medium_12 */
            /* get font 'font_inter_medium_12' from a C array */
            font_inter_medium_12 = &font_inter_medium_12_data;

        }
        if (!font_inter_bold_11) {
            /* font_inter_bold_11 */
            /* get font 'font_inter_bold_11' from a C array */
            font_inter_bold_11 = &font_inter_bold_11_data;

        }
        if (!font_inter_semi_bold_10) {
            /* font_inter_semi_bold_10 */
            /* get font 'font_inter_semi_bold_10' from a C array */
            font_inter_semi_bold_10 = &font_inter_semi_bold_10_data;

        }
        if (!font_inter_regular_12_5) {
            /* font_inter_regular_12_5 */
            /* get font 'font_inter_regular_12_5' from a C array */
            font_inter_regular_12_5 = &font_inter_regular_12_5_data;

        }
        if (!font_gabarito_semibold_19_200000762939453) {
            /* font_gabarito_semibold_19_200000762939453 */
            /* get font 'font_gabarito_semibold_19_200000762939453' from a C array */
            font_gabarito_semibold_19_200000762939453 = &font_gabarito_semibold_19_200000762939453_data;

        }
        if (!font_gabarito_semibold_43_52000427246094) {
            /* font_gabarito_semibold_43_52000427246094 */
            /* get font 'font_gabarito_semibold_43_52000427246094' from a C array */
            font_gabarito_semibold_43_52000427246094 = &font_gabarito_semibold_43_52000427246094_data;

        }
        if (!font_gabarito_regular_19_200000762939453) {
            /* font_gabarito_regular_19_200000762939453 */
            /* get font 'font_gabarito_regular_19_200000762939453' from a C array */
            font_gabarito_regular_19_200000762939453 = &font_gabarito_regular_19_200000762939453_data;

        }
        if (!font_gabarito_regular_15_360000610351562) {
            /* font_gabarito_regular_15_360000610351562 */
            /* get font 'font_gabarito_regular_15_360000610351562' from a C array */
            font_gabarito_regular_15_360000610351562 = &font_gabarito_regular_15_360000610351562_data;

        }
        if (!font_gabarito_semibold_28_160001754760742) {
            /* font_gabarito_semibold_28_160001754760742 */
            /* get font 'font_gabarito_semibold_28_160001754760742' from a C array */
            font_gabarito_semibold_28_160001754760742 = &font_gabarito_semibold_28_160001754760742_data;

        }
        if (!font_gabarito_regular_16_64000129699707) {
            /* font_gabarito_regular_16_64000129699707 */
            /* get font 'font_gabarito_regular_16_64000129699707' from a C array */
            font_gabarito_regular_16_64000129699707 = &font_gabarito_regular_16_64000129699707_data;

        }
        if (!font_gabarito_medium_19_200000762939453) {
            /* font_gabarito_medium_19_200000762939453 */
            /* get font 'font_gabarito_medium_19_200000762939453' from a C array */
            font_gabarito_medium_19_200000762939453 = &font_gabarito_medium_19_200000762939453_data;

        }
        if (!font_gabarito_medium_15_360000610351562) {
            /* font_gabarito_medium_15_360000610351562 */
            /* get font 'font_gabarito_medium_15_360000610351562' from a C array */
            font_gabarito_medium_15_360000610351562 = &font_gabarito_medium_15_360000610351562_data;

        }
        if (!font_gabarito_semibold_24_57600212097168) {
            /* font_gabarito_semibold_24_57600212097168 */
            /* get font 'font_gabarito_semibold_24_57600212097168' from a C array */
            font_gabarito_semibold_24_57600212097168 = &font_gabarito_semibold_24_57600212097168_data;

        }
        if (!font_gabarito_regular_24_57600212097168) {
            /* font_gabarito_regular_24_57600212097168 */
            /* get font 'font_gabarito_regular_24_57600212097168' from a C array */
            font_gabarito_regular_24_57600212097168 = &font_gabarito_regular_24_57600212097168_data;

        }
        if (!font_gabarito_medium_21_299203872680664) {
            /* font_gabarito_medium_21_299203872680664 */
            /* get font 'font_gabarito_medium_21_299203872680664' from a C array */
            font_gabarito_medium_21_299203872680664 = &font_gabarito_medium_21_299203872680664_data;

        }
        if (!font_gabarito_semibold_36_044803619384766) {
            /* font_gabarito_semibold_36_044803619384766 */
            /* get font 'font_gabarito_semibold_36_044803619384766' from a C array */
            font_gabarito_semibold_36_044803619384766 = &font_gabarito_semibold_36_044803619384766_data;

        }
        if (!font_gabarito_semibold_40_96000289916992) {
            /* font_gabarito_semibold_40_96000289916992 */
            /* get font 'font_gabarito_semibold_40_96000289916992' from a C array */
            font_gabarito_semibold_40_96000289916992 = &font_gabarito_semibold_40_96000289916992_data;

        }
        if (!font_gabarito_semibold_33_28000259399414) {
            /* font_gabarito_semibold_33_28000259399414 */
            /* get font 'font_gabarito_semibold_33_28000259399414' from a C array */
            font_gabarito_semibold_33_28000259399414 = &font_gabarito_semibold_33_28000259399414_data;

        }
        if (!font_gabarito_semibold_23_040000915527344) {
            /* font_gabarito_semibold_23_040000915527344 */
            /* get font 'font_gabarito_semibold_23_040000915527344' from a C array */
            font_gabarito_semibold_23_040000915527344 = &font_gabarito_semibold_23_040000915527344_data;

        }
        if (!font_gabarito_semibold_40_959999084472656) {
            /* font_gabarito_semibold_40_959999084472656 */
            /* get font 'font_gabarito_semibold_40_959999084472656' from a C array */
            font_gabarito_semibold_40_959999084472656 = &font_gabarito_semibold_40_959999084472656_data;

        }
        if (!font_gabarito_regular_19_19999885559082) {
            /* font_gabarito_regular_19_19999885559082 */
            /* get font 'font_gabarito_regular_19_19999885559082' from a C array */
            font_gabarito_regular_19_19999885559082 = &font_gabarito_regular_19_19999885559082_data;

        }
        if (!font_gabarito_semibold_19_19999885559082) {
            /* font_gabarito_semibold_19_19999885559082 */
            /* get font 'font_gabarito_semibold_19_19999885559082' from a C array */
            font_gabarito_semibold_19_19999885559082 = &font_gabarito_semibold_19_19999885559082_data;

        }
        if (!font_gabarito_regular_15_359999656677246) {
            /* font_gabarito_regular_15_359999656677246 */
            /* get font 'font_gabarito_regular_15_359999656677246' from a C array */
            font_gabarito_regular_15_359999656677246 = &font_gabarito_regular_15_359999656677246_data;

        }
        if (!font_gabarito_semibold_33_279998779296875) {
            /* font_gabarito_semibold_33_279998779296875 */
            /* get font 'font_gabarito_semibold_33_279998779296875' from a C array */
            font_gabarito_semibold_33_279998779296875 = &font_gabarito_semibold_33_279998779296875_data;

        }
        if (!font_gabarito_semibold_28_15999984741211) {
            /* font_gabarito_semibold_28_15999984741211 */
            /* get font 'font_gabarito_semibold_28_15999984741211' from a C array */
            font_gabarito_semibold_28_15999984741211 = &font_gabarito_semibold_28_15999984741211_data;

        }
        if (!font_gabarito_semibold_43_52000045776367) {
            /* font_gabarito_semibold_43_52000045776367 */
            /* get font 'font_gabarito_semibold_43_52000045776367' from a C array */
            font_gabarito_semibold_43_52000045776367 = &font_gabarito_semibold_43_52000045776367_data;

        }
        if (!font_gabarito_medium_14_079999923706055) {
            /* font_gabarito_medium_14_079999923706055 */
            /* get font 'font_gabarito_medium_14_079999923706055' from a C array */
            font_gabarito_medium_14_079999923706055 = &font_gabarito_medium_14_079999923706055_data;

        }
        if (!font_gabarito_semibold_24_576000213623047) {
            /* font_gabarito_semibold_24_576000213623047 */
            /* get font 'font_gabarito_semibold_24_576000213623047' from a C array */
            font_gabarito_semibold_24_576000213623047 = &font_gabarito_semibold_24_576000213623047_data;

        }
        if (!font_gabarito_regular_24_576000213623047) {
            /* font_gabarito_regular_24_576000213623047 */
            /* get font 'font_gabarito_regular_24_576000213623047' from a C array */
            font_gabarito_regular_24_576000213623047 = &font_gabarito_regular_24_576000213623047_data;

        }
        if (!font_gabarito_medium_21_29920196533203) {
            /* font_gabarito_medium_21_29920196533203 */
            /* get font 'font_gabarito_medium_21_29920196533203' from a C array */
            font_gabarito_medium_21_29920196533203 = &font_gabarito_medium_21_29920196533203_data;

        }
        if (!font_gabarito_semibold_36_0447998046875) {
            /* font_gabarito_semibold_36_0447998046875 */
            /* get font 'font_gabarito_semibold_36_0447998046875' from a C array */
            font_gabarito_semibold_36_0447998046875 = &font_gabarito_semibold_36_0447998046875_data;

        }
        if (!font_gabarito_bold_168_95999145507812) {
            /* font_gabarito_bold_168_95999145507812 */
            /* get font 'font_gabarito_bold_168_95999145507812' from a C array */
            font_gabarito_bold_168_95999145507812 = &font_gabarito_bold_168_95999145507812_data;

        }
        if (!font_gabarito_medium_56_31999969482422) {
            /* font_gabarito_medium_56_31999969482422 */
            /* get font 'font_gabarito_medium_56_31999969482422' from a C array */
            font_gabarito_medium_56_31999969482422 = &font_gabarito_medium_56_31999969482422_data;

        }
        if (!font_gabarito_semibold_23_03999900817871) {
            /* font_gabarito_semibold_23_03999900817871 */
            /* get font 'font_gabarito_semibold_23_03999900817871' from a C array */
            font_gabarito_semibold_23_03999900817871 = &font_gabarito_semibold_23_03999900817871_data;

        }
        if (!font_gabarito_semibold_30_719999313354492) {
            /* font_gabarito_semibold_30_719999313354492 */
            /* get font 'font_gabarito_semibold_30_719999313354492' from a C array */
            font_gabarito_semibold_30_719999313354492 = &font_gabarito_semibold_30_719999313354492_data;

        }
        if (!font_gabarito_regular_16_639999389648438) {
            /* font_gabarito_regular_16_639999389648438 */
            /* get font 'font_gabarito_regular_16_639999389648438' from a C array */
            font_gabarito_regular_16_639999389648438 = &font_gabarito_regular_16_639999389648438_data;

        }
        if (!font_gabarito_regular_14_079999923706055) {
            /* font_gabarito_regular_14_079999923706055 */
            /* get font 'font_gabarito_regular_14_079999923706055' from a C array */
            font_gabarito_regular_14_079999923706055 = &font_gabarito_regular_14_079999923706055_data;

        }
        if (!font_gabarito_medium_16_639999389648438) {
            /* font_gabarito_medium_16_639999389648438 */
            /* get font 'font_gabarito_medium_16_639999389648438' from a C array */
            font_gabarito_medium_16_639999389648438 = &font_gabarito_medium_16_639999389648438_data;

        }
        if (!font_gabarito_semibold_25_599998474121094) {
            /* font_gabarito_semibold_25_599998474121094 */
            /* get font 'font_gabarito_semibold_25_599998474121094' from a C array */
            font_gabarito_semibold_25_599998474121094 = &font_gabarito_semibold_25_599998474121094_data;

        }
        if (!font_gabarito_medium_19_19999885559082) {
            /* font_gabarito_medium_19_19999885559082 */
            /* get font 'font_gabarito_medium_19_19999885559082' from a C array */
            font_gabarito_medium_19_19999885559082 = &font_gabarito_medium_19_19999885559082_data;

        }
        if (!font_gabarito_medium_15_359999656677246) {
            /* font_gabarito_medium_15_359999656677246 */
            /* get font 'font_gabarito_medium_15_359999656677246' from a C array */
            font_gabarito_medium_15_359999656677246 = &font_gabarito_medium_15_359999656677246_data;

        }
        if (!font_gabarito_medium_16_64000129699707) {
            /* font_gabarito_medium_16_64000129699707 */
            /* get font 'font_gabarito_medium_16_64000129699707' from a C array */
            font_gabarito_medium_16_64000129699707 = &font_gabarito_medium_16_64000129699707_data;

        }
    }
    #endif

    /*----------------
     * Images
     *----------------*/

    /* Targets: any */
    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        /* image_qr_receipt_115x115 */
        if (!image_qr_receipt_115x115) {
            image_qr_receipt_115x115 = &image_qr_receipt_115x115_data;
        }
        /* image_qr_receipt_64x64 */
        if (!image_qr_receipt_64x64) {
            image_qr_receipt_64x64 = &image_qr_receipt_64x64_data;
        }
        /* image_plug_large */
        if (!image_plug_large) {
            image_plug_large = &image_plug_large_data;
        }
        /* image_back_byd_1039x365 */
        if (!image_back_byd_1039x365) {
            image_back_byd_1039x365 = &image_back_byd_1039x365_data;
        }
        /* image_back_byd_755x265 */
        if (!image_back_byd_755x265) {
            image_back_byd_755x265 = &image_back_byd_755x265_data;
        }
        /* image_back_byd_425x149 */
        if (!image_back_byd_425x149) {
            image_back_byd_425x149 = &image_back_byd_425x149_data;
        }
        /* image_4 */
        if (!image_4) {
            image_4 = &image_4_data;
        }
        /* image_front_byd */
        if (!image_front_byd) {
            image_front_byd = &image_front_byd_data;
        }
        /* image_icon_supercharge_green_24419 */
        if (!image_icon_supercharge_green_24419) {
            image_icon_supercharge_green_24419 = &image_icon_supercharge_green_24419_data;
        }
        /* image_icon_zap_19913 */
        if (!image_icon_zap_19913) {
            image_icon_zap_19913 = &image_icon_zap_19913_data;
        }
        /* image_icon_plug_19916 */
        if (!image_icon_plug_19916) {
            image_icon_plug_19916 = &image_icon_plug_19916_data;
        }
        /* image_icon_supercharge */
        if (!image_icon_supercharge) {
            image_icon_supercharge = &image_icon_supercharge_data;
        }
        /* image_icon_nfc_19919 */
        if (!image_icon_nfc_19919) {
            image_icon_nfc_19919 = &image_icon_nfc_19919_data;
        }
        /* image_vec_263_32 */
        if (!image_vec_263_32) {
            image_vec_263_32 = &image_vec_263_32_data;
        }
        /* image_icon_diagnostic_323653 */
        if (!image_icon_diagnostic_323653) {
            image_icon_diagnostic_323653 = &image_icon_diagnostic_323653_data;
        }
        /* image_icon_settings_1988 */
        if (!image_icon_settings_1988) {
            image_icon_settings_1988 = &image_icon_settings_1988_data;
        }
        /* image_vec_263_263 */
        if (!image_vec_263_263) {
            image_vec_263_263 = &image_vec_263_263_data;
        }
        /* image_icon_back_323661 */
        if (!image_icon_back_323661) {
            image_icon_back_323661 = &image_icon_back_323661_data;
        }
        /* image_icon_close_30435 */
        if (!image_icon_close_30435) {
            image_icon_close_30435 = &image_icon_close_30435_data;
        }
        /* image_vec_270_4 */
        if (!image_vec_270_4) {
            image_vec_270_4 = &image_vec_270_4_data;
        }
        /* image_vec_270_5 */
        if (!image_vec_270_5) {
            image_vec_270_5 = &image_vec_270_5_data;
        }
        /* image_vec_270_6 */
        if (!image_vec_270_6) {
            image_vec_270_6 = &image_vec_270_6_data;
        }
        /* image_vec_270_7 */
        if (!image_vec_270_7) {
            image_vec_270_7 = &image_vec_270_7_data;
        }
        /* image_vec_270_8 */
        if (!image_vec_270_8) {
            image_vec_270_8 = &image_vec_270_8_data;
        }
        /* image_lucide_nfc */
        if (!image_lucide_nfc) {
            image_lucide_nfc = &image_lucide_nfc_data;
        }
        /* image_vec_273_184 */
        if (!image_vec_273_184) {
            image_vec_273_184 = &image_vec_273_184_data;
        }
        /* image_vec_273_185 */
        if (!image_vec_273_185) {
            image_vec_273_185 = &image_vec_273_185_data;
        }
        /* image_vec_273_186 */
        if (!image_vec_273_186) {
            image_vec_273_186 = &image_vec_273_186_data;
        }
        /* image_vec_328_444 */
        if (!image_vec_328_444) {
            image_vec_328_444 = &image_vec_328_444_data;
        }
        /* img_wheel_base */
        if (!img_wheel_base) {
            img_wheel_base = &img_wheel_base_data;
        }
        /* img_wheel_rim */
        if (!img_wheel_rim) {
            img_wheel_rim = &img_wheel_rim_data;
        }
        /* img_wheel_base_98 */
        if (!img_wheel_base_98) {
            img_wheel_base_98 = &img_wheel_base_98_data;
        }
        /* img_wheel_rim_98 */
        if (!img_wheel_rim_98) {
            img_wheel_rim_98 = &img_wheel_rim_98_data;
        }
    }
    #endif

    /*----------------
     * Global styles
     *----------------*/

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_heading_global);
        lv_style_init(&style_font_title_global);
        lv_style_init(&style_body_global);
        lv_style_init(&style_body_strong_global);
        lv_style_init(&style_chip_global);
        lv_style_init(&style_caption_global);
        lv_style_init(&style_overline_global);
        lv_style_init(&style_stat_lg_global);
        lv_style_init(&style_stat_md_global);
        lv_style_init(&style_hero_global);
        lv_style_init(&style_hero_unit_global);
        lv_style_init(&style_font_subtitle_global);
        lv_style_init(&style_stat_sm_global);
        lv_style_init(&style_stat_xs_global);
        lv_style_init(&style_font_label_global);
        lv_style_init(&style_font_meta_global);
        lv_style_init(&style_badge_global);
        lv_style_init(&style_micro_global);
        lv_style_init(&style_shadow_card_global);
        lv_style_init(&style_shadow_modal_global);
        lv_style_init(&style_shadow_knob_global);
        lv_style_init(&style_screen_base_global);
        lv_style_init(&style_bar_b_danger_global);
        lv_style_init(&style_bar_b_green_global);
        lv_style_init(&style_bar_b_warn_global);
        lv_style_init(&style_chip_card_dot_green_global);
        lv_style_init(&style_chip_card_dot_grey_global);
        lv_style_init(&style_chip_card_dot_red_global);
        lv_style_init(&style_chip_card_green_global);
        lv_style_init(&style_chip_card_grey_global);
        lv_style_init(&style_chip_card_label_green_global);
        lv_style_init(&style_chip_card_label_grey_global);
        lv_style_init(&style_chip_card_label_red_global);
        lv_style_init(&style_chip_card_red_global);
        lv_style_init(&style_chip_header_green_global);
        lv_style_init(&style_chip_header_grey_global);
        lv_style_init(&style_chip_header_orange_global);

        lv_style_set_text_font(&style_heading_global, font_gabarito_semibold_32);
        lv_style_set_text_font(&style_font_title_global, font_gabarito_semibold_22);
        lv_style_set_text_font(&style_body_global, font_gabarito_regular_15);
        lv_style_set_text_font(&style_body_strong_global, font_gabarito_semibold_15);
        lv_style_set_text_font(&style_chip_global, font_gabarito_medium_13);
        lv_style_set_text_font(&style_caption_global, font_gabarito_regular_12);
        lv_style_set_text_font(&style_overline_global, font_gabarito_medium_11);
        lv_style_set_text_letter_space(&style_overline_global, 1);
        lv_style_set_text_font(&style_stat_lg_global, font_gabarito_semibold_34);
        lv_style_set_text_letter_space(&style_stat_lg_global, -1);
        lv_style_set_text_font(&style_stat_md_global, font_gabarito_semibold_26);
        lv_style_set_text_font(&style_hero_global, font_gabarito_bold_132);
        lv_style_set_text_letter_space(&style_hero_global, -5);
        lv_style_set_text_font(&style_hero_unit_global, font_gabarito_medium_44);
        lv_style_set_text_letter_space(&style_hero_unit_global, -1);
        lv_style_set_text_font(&style_font_subtitle_global, font_gabarito_semibold_18);
        lv_style_set_text_font(&style_stat_sm_global, font_gabarito_semibold_24);
        lv_style_set_text_font(&style_stat_xs_global, font_gabarito_semibold_20);
        lv_style_set_text_font(&style_font_label_global, font_gabarito_medium_15);
        lv_style_set_text_font(&style_font_meta_global, font_gabarito_regular_13);
        lv_style_set_text_font(&style_badge_global, font_gabarito_medium_12);
        lv_style_set_text_font(&style_micro_global, font_gabarito_regular_11);
        lv_style_set_shadow_width(&style_shadow_card_global, 24);
        lv_style_set_shadow_offset_y(&style_shadow_card_global, 8);
        lv_style_set_shadow_spread(&style_shadow_card_global, -6);
        lv_style_set_shadow_color(&style_shadow_card_global, lv_color_hex(0x141C22));
        lv_style_set_shadow_opa(&style_shadow_card_global, 26);
        lv_style_set_shadow_width(&style_shadow_modal_global, 50);
        lv_style_set_shadow_offset_y(&style_shadow_modal_global, 20);
        lv_style_set_shadow_spread(&style_shadow_modal_global, -12);
        lv_style_set_shadow_color(&style_shadow_modal_global, lv_color_hex(0x05070A));
        lv_style_set_shadow_opa(&style_shadow_modal_global, 102);
        lv_style_set_shadow_width(&style_shadow_knob_global, 6);
        lv_style_set_shadow_offset_y(&style_shadow_knob_global, 2);
        lv_style_set_shadow_spread(&style_shadow_knob_global, -1);
        lv_style_set_shadow_color(&style_shadow_knob_global, lv_color_hex(0x141C22));
        lv_style_set_shadow_opa(&style_shadow_knob_global, 46);
        lv_style_set_border_width(&style_screen_base_global, 0);
        lv_style_set_radius(&style_screen_base_global, 0);
        lv_style_set_shadow_width(&style_screen_base_global, 0);
        lv_style_set_shadow_opa(&style_screen_base_global, 0);
        lv_style_set_bg_color(&style_bar_b_danger_global, CONST_DANGER_GLOBAL);
        lv_style_set_bg_color(&style_bar_b_green_global, CONST_ACCENT_GLOBAL);
        lv_style_set_bg_color(&style_bar_b_warn_global, CONST_WARN_GLOBAL);
        lv_style_set_bg_color(&style_chip_card_dot_green_global, CONST_ACCENT_GLOBAL);
        lv_style_set_bg_opa(&style_chip_card_dot_green_global, 255);
        lv_style_set_bg_color(&style_chip_card_dot_grey_global, CONST_TEXT_SECONDARY_GLOBAL);
        lv_style_set_bg_color(&style_chip_card_dot_red_global, CONST_DANGER_GLOBAL);
        lv_style_set_bg_opa(&style_chip_card_dot_red_global, 255);
        lv_style_set_width(&style_chip_card_green_global, 92);
        lv_style_set_pad_left(&style_chip_card_green_global, 12);
        lv_style_set_pad_column(&style_chip_card_green_global, 8);
        lv_style_set_bg_color(&style_chip_card_green_global, CONST_TINT_ACCENT_GLOBAL);
        lv_style_set_bg_opa(&style_chip_card_green_global, 255);
        lv_style_set_width(&style_chip_card_grey_global, LV_SIZE_CONTENT);
        lv_style_set_pad_left(&style_chip_card_grey_global, 8);
        lv_style_set_pad_column(&style_chip_card_grey_global, 4);
        lv_style_set_bg_color(&style_chip_card_grey_global, CONST_TINT_NEUTRAL_GLOBAL);
        lv_style_set_text_color(&style_chip_card_label_green_global, CONST_ACCENT_GLOBAL);
        lv_style_set_text_color(&style_chip_card_label_grey_global, CONST_TEXT_SECONDARY_GLOBAL);
        lv_style_set_text_color(&style_chip_card_label_red_global, CONST_DANGER_GLOBAL);
        lv_style_set_width(&style_chip_card_red_global, LV_SIZE_CONTENT);
        lv_style_set_pad_left(&style_chip_card_red_global, 8);
        lv_style_set_pad_column(&style_chip_card_red_global, 4);
        lv_style_set_bg_color(&style_chip_card_red_global, CONST_TINT_DANGER_GLOBAL);
        lv_style_set_bg_opa(&style_chip_card_red_global, 255);
        lv_style_set_bg_color(&style_chip_header_green_global, CONST_ACCENT_GLOBAL);
        lv_style_set_bg_color(&style_chip_header_grey_global, CONST_TEXT_SECONDARY_GLOBAL);
        lv_style_set_bg_opa(&style_chip_header_grey_global, 255);
        lv_style_set_bg_color(&style_chip_header_orange_global, CONST_WARN_GLOBAL);
        lv_style_set_bg_opa(&style_chip_header_orange_global, 255);

        style_inited = true;
    }

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&subject_alert_volume, 40);
    lv_subject_init_int(&subject_bay_reserve, 0);
    lv_subject_init_int(&subject_cable_thermal, 42);
    lv_subject_init_int(&subject_card_ending, 4291);
    lv_subject_init_int(&subject_chg_limit, 80);
    lv_subject_init_int(&subject_chg_pct, 21);
    lv_subject_init_int(&subject_contactless, 0);
    lv_subject_init_int(&subject_current_cost, 4);
    lv_subject_init_int(&subject_km_added, 124);
    lv_subject_init_int(&subject_power_stage, 58);
    lv_subject_init_int(&subject_preferences_modal_state, 0);
    lv_subject_init_int(&subject_screen_brightness, 100);
    static char subject_time_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_time_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_time,
                           subject_time_buf,
                           subject_time_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "11:35"
                          );
    lv_subject_init_int(&subject_wifi, 0);
    lv_subject_init_int(&subject_unbound_card_bay_bar, 0);
    lv_subject_init_int(&subject_unbound_card_bay_value_card_bay_2, 47);
    lv_subject_init_int(&subject_unbound_field_slider_control_slider, 0);
    lv_subject_init_int(&subject_unbound_field_slider_value_field_slider_2, 70);
    lv_subject_init_int(&subject_unbound_row_toggle_control_switch, 0);
    static char subject_unbound_tile_stat_value_tile_stat_2_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_unbound_tile_stat_value_tile_stat_2_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_unbound_tile_stat_value_tile_stat_2,
                           subject_unbound_tile_stat_value_tile_stat_2_buf,
                           subject_unbound_tile_stat_value_tile_stat_2_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "42.0"
                          );
    lv_subject_init_int(&subject_language_id, 0);
    lv_subject_init_int(&subject_animations, 0);

    /*----------------
     * Translations
     *----------------*/

    #ifndef LV_EDITOR_PREVIEW
        lv_translation_add_static(translation_languages, translation_tags, translation_texts);
        lv_translation_set_language(translation_languages[0]);
    #endif

#if defined(LV_USE_XML) && LV_USE_XML
    /* Register widgets */

    /* Check all fonts / default if needed. This prevents fonts that are used in one target but
       defined in another from causing assertion failures during rendering of the Preview. */
    check_font(&font_gabarito_semibold_32, "font_gabarito_semibold_32");
    check_font(&font_gabarito_semibold_22, "font_gabarito_semibold_22");
    check_font(&font_gabarito_regular_15, "font_gabarito_regular_15");
    check_font(&font_gabarito_semibold_15, "font_gabarito_semibold_15");
    check_font(&font_gabarito_medium_13, "font_gabarito_medium_13");
    check_font(&font_gabarito_regular_12, "font_gabarito_regular_12");
    check_font(&font_gabarito_medium_11, "font_gabarito_medium_11");
    check_font(&font_gabarito_semibold_34, "font_gabarito_semibold_34");
    check_font(&font_gabarito_semibold_26, "font_gabarito_semibold_26");
    check_font(&font_gabarito_bold_132, "font_gabarito_bold_132");
    check_font(&font_gabarito_medium_44, "font_gabarito_medium_44");
    check_font(&font_gabarito_semibold_18, "font_gabarito_semibold_18");
    check_font(&font_gabarito_semibold_24, "font_gabarito_semibold_24");
    check_font(&font_gabarito_semibold_20, "font_gabarito_semibold_20");
    check_font(&font_gabarito_medium_15, "font_gabarito_medium_15");
    check_font(&font_gabarito_regular_13, "font_gabarito_regular_13");
    check_font(&font_gabarito_medium_12, "font_gabarito_medium_12");
    check_font(&font_gabarito_regular_11, "font_gabarito_regular_11");
    check_font(&font_inter_bold_86, "font_inter_bold_86");
    check_font(&font_inter_semi_bold_41, "font_inter_semi_bold_41");
    check_font(&font_inter_semi_bold_38, "font_inter_semi_bold_38");
    check_font(&font_inter_semi_bold_30, "font_inter_semi_bold_30");
    check_font(&font_inter_semi_bold_13, "font_inter_semi_bold_13");
    check_font(&font_inter_bold_46, "font_inter_bold_46");
    check_font(&font_inter_regular_20, "font_inter_regular_20");
    check_font(&font_inter_medium_15, "font_inter_medium_15");
    check_font(&font_inter_semi_bold_15, "font_inter_semi_bold_15");
    check_font(&font_inter_bold_14, "font_inter_bold_14");
    check_font(&font_inter_semi_bold_12, "font_inter_semi_bold_12");
    check_font(&font_inter_semi_bold_21, "font_inter_semi_bold_21");
    check_font(&font_inter_regular_15, "font_inter_regular_15");
    check_font(&font_inter_medium_12, "font_inter_medium_12");
    check_font(&font_inter_bold_11, "font_inter_bold_11");
    check_font(&font_inter_semi_bold_10, "font_inter_semi_bold_10");
    check_font(&font_inter_regular_12_5, "font_inter_regular_12_5");
    check_font(&font_gabarito_semibold_19_200000762939453, "font_gabarito_semibold_19_200000762939453");
    check_font(&font_gabarito_semibold_43_52000427246094, "font_gabarito_semibold_43_52000427246094");
    check_font(&font_gabarito_regular_19_200000762939453, "font_gabarito_regular_19_200000762939453");
    check_font(&font_gabarito_regular_15_360000610351562, "font_gabarito_regular_15_360000610351562");
    check_font(&font_gabarito_semibold_28_160001754760742, "font_gabarito_semibold_28_160001754760742");
    check_font(&font_gabarito_regular_16_64000129699707, "font_gabarito_regular_16_64000129699707");
    check_font(&font_gabarito_medium_19_200000762939453, "font_gabarito_medium_19_200000762939453");
    check_font(&font_gabarito_medium_15_360000610351562, "font_gabarito_medium_15_360000610351562");
    check_font(&font_gabarito_semibold_24_57600212097168, "font_gabarito_semibold_24_57600212097168");
    check_font(&font_gabarito_regular_24_57600212097168, "font_gabarito_regular_24_57600212097168");
    check_font(&font_gabarito_medium_21_299203872680664, "font_gabarito_medium_21_299203872680664");
    check_font(&font_gabarito_semibold_36_044803619384766, "font_gabarito_semibold_36_044803619384766");
    check_font(&font_gabarito_semibold_40_96000289916992, "font_gabarito_semibold_40_96000289916992");
    check_font(&font_gabarito_semibold_33_28000259399414, "font_gabarito_semibold_33_28000259399414");
    check_font(&font_gabarito_semibold_23_040000915527344, "font_gabarito_semibold_23_040000915527344");
    check_font(&font_gabarito_semibold_40_959999084472656, "font_gabarito_semibold_40_959999084472656");
    check_font(&font_gabarito_regular_19_19999885559082, "font_gabarito_regular_19_19999885559082");
    check_font(&font_gabarito_semibold_19_19999885559082, "font_gabarito_semibold_19_19999885559082");
    check_font(&font_gabarito_regular_15_359999656677246, "font_gabarito_regular_15_359999656677246");
    check_font(&font_gabarito_semibold_33_279998779296875, "font_gabarito_semibold_33_279998779296875");
    check_font(&font_gabarito_semibold_28_15999984741211, "font_gabarito_semibold_28_15999984741211");
    check_font(&font_gabarito_semibold_43_52000045776367, "font_gabarito_semibold_43_52000045776367");
    check_font(&font_gabarito_medium_14_079999923706055, "font_gabarito_medium_14_079999923706055");
    check_font(&font_gabarito_semibold_24_576000213623047, "font_gabarito_semibold_24_576000213623047");
    check_font(&font_gabarito_regular_24_576000213623047, "font_gabarito_regular_24_576000213623047");
    check_font(&font_gabarito_medium_21_29920196533203, "font_gabarito_medium_21_29920196533203");
    check_font(&font_gabarito_semibold_36_0447998046875, "font_gabarito_semibold_36_0447998046875");
    check_font(&font_gabarito_bold_168_95999145507812, "font_gabarito_bold_168_95999145507812");
    check_font(&font_gabarito_medium_56_31999969482422, "font_gabarito_medium_56_31999969482422");
    check_font(&font_gabarito_semibold_23_03999900817871, "font_gabarito_semibold_23_03999900817871");
    check_font(&font_gabarito_semibold_30_719999313354492, "font_gabarito_semibold_30_719999313354492");
    check_font(&font_gabarito_regular_16_639999389648438, "font_gabarito_regular_16_639999389648438");
    check_font(&font_gabarito_regular_14_079999923706055, "font_gabarito_regular_14_079999923706055");
    check_font(&font_gabarito_medium_16_639999389648438, "font_gabarito_medium_16_639999389648438");
    check_font(&font_gabarito_semibold_25_599998474121094, "font_gabarito_semibold_25_599998474121094");
    check_font(&font_gabarito_medium_19_19999885559082, "font_gabarito_medium_19_19999885559082");
    check_font(&font_gabarito_medium_15_359999656677246, "font_gabarito_medium_15_359999656677246");
    check_font(&font_gabarito_medium_16_64000129699707, "font_gabarito_medium_16_64000129699707");

    /* Register fonts */
    lv_xml_register_font(NULL, "font_gabarito_semibold_32", font_gabarito_semibold_32);
    lv_xml_register_font(NULL, "font_gabarito_semibold_22", font_gabarito_semibold_22);
    lv_xml_register_font(NULL, "font_gabarito_regular_15", font_gabarito_regular_15);
    lv_xml_register_font(NULL, "font_gabarito_semibold_15", font_gabarito_semibold_15);
    lv_xml_register_font(NULL, "font_gabarito_medium_13", font_gabarito_medium_13);
    lv_xml_register_font(NULL, "font_gabarito_regular_12", font_gabarito_regular_12);
    lv_xml_register_font(NULL, "font_gabarito_medium_11", font_gabarito_medium_11);
    lv_xml_register_font(NULL, "font_gabarito_semibold_34", font_gabarito_semibold_34);
    lv_xml_register_font(NULL, "font_gabarito_semibold_26", font_gabarito_semibold_26);
    lv_xml_register_font(NULL, "font_gabarito_bold_132", font_gabarito_bold_132);
    lv_xml_register_font(NULL, "font_gabarito_medium_44", font_gabarito_medium_44);
    lv_xml_register_font(NULL, "font_gabarito_semibold_18", font_gabarito_semibold_18);
    lv_xml_register_font(NULL, "font_gabarito_semibold_24", font_gabarito_semibold_24);
    lv_xml_register_font(NULL, "font_gabarito_semibold_20", font_gabarito_semibold_20);
    lv_xml_register_font(NULL, "font_gabarito_medium_15", font_gabarito_medium_15);
    lv_xml_register_font(NULL, "font_gabarito_regular_13", font_gabarito_regular_13);
    lv_xml_register_font(NULL, "font_gabarito_medium_12", font_gabarito_medium_12);
    lv_xml_register_font(NULL, "font_gabarito_regular_11", font_gabarito_regular_11);
    lv_xml_register_font(NULL, "font_inter_bold_86", font_inter_bold_86);
    lv_xml_register_font(NULL, "font_inter_semi_bold_41", font_inter_semi_bold_41);
    lv_xml_register_font(NULL, "font_inter_semi_bold_38", font_inter_semi_bold_38);
    lv_xml_register_font(NULL, "font_inter_semi_bold_30", font_inter_semi_bold_30);
    lv_xml_register_font(NULL, "font_inter_semi_bold_13", font_inter_semi_bold_13);
    lv_xml_register_font(NULL, "font_inter_bold_46", font_inter_bold_46);
    lv_xml_register_font(NULL, "font_inter_regular_20", font_inter_regular_20);
    lv_xml_register_font(NULL, "font_inter_medium_15", font_inter_medium_15);
    lv_xml_register_font(NULL, "font_inter_semi_bold_15", font_inter_semi_bold_15);
    lv_xml_register_font(NULL, "font_inter_bold_14", font_inter_bold_14);
    lv_xml_register_font(NULL, "font_inter_semi_bold_12", font_inter_semi_bold_12);
    lv_xml_register_font(NULL, "font_inter_semi_bold_21", font_inter_semi_bold_21);
    lv_xml_register_font(NULL, "font_inter_regular_15", font_inter_regular_15);
    lv_xml_register_font(NULL, "font_inter_medium_12", font_inter_medium_12);
    lv_xml_register_font(NULL, "font_inter_bold_11", font_inter_bold_11);
    lv_xml_register_font(NULL, "font_inter_semi_bold_10", font_inter_semi_bold_10);
    lv_xml_register_font(NULL, "font_inter_regular_12_5", font_inter_regular_12_5);
    lv_xml_register_font(NULL, "font_gabarito_semibold_19_200000762939453", font_gabarito_semibold_19_200000762939453);
    lv_xml_register_font(NULL, "font_gabarito_semibold_43_52000427246094", font_gabarito_semibold_43_52000427246094);
    lv_xml_register_font(NULL, "font_gabarito_regular_19_200000762939453", font_gabarito_regular_19_200000762939453);
    lv_xml_register_font(NULL, "font_gabarito_regular_15_360000610351562", font_gabarito_regular_15_360000610351562);
    lv_xml_register_font(NULL, "font_gabarito_semibold_28_160001754760742", font_gabarito_semibold_28_160001754760742);
    lv_xml_register_font(NULL, "font_gabarito_regular_16_64000129699707", font_gabarito_regular_16_64000129699707);
    lv_xml_register_font(NULL, "font_gabarito_medium_19_200000762939453", font_gabarito_medium_19_200000762939453);
    lv_xml_register_font(NULL, "font_gabarito_medium_15_360000610351562", font_gabarito_medium_15_360000610351562);
    lv_xml_register_font(NULL, "font_gabarito_semibold_24_57600212097168", font_gabarito_semibold_24_57600212097168);
    lv_xml_register_font(NULL, "font_gabarito_regular_24_57600212097168", font_gabarito_regular_24_57600212097168);
    lv_xml_register_font(NULL, "font_gabarito_medium_21_299203872680664", font_gabarito_medium_21_299203872680664);
    lv_xml_register_font(NULL, "font_gabarito_semibold_36_044803619384766", font_gabarito_semibold_36_044803619384766);
    lv_xml_register_font(NULL, "font_gabarito_semibold_40_96000289916992", font_gabarito_semibold_40_96000289916992);
    lv_xml_register_font(NULL, "font_gabarito_semibold_33_28000259399414", font_gabarito_semibold_33_28000259399414);
    lv_xml_register_font(NULL, "font_gabarito_semibold_23_040000915527344", font_gabarito_semibold_23_040000915527344);
    lv_xml_register_font(NULL, "font_gabarito_semibold_40_959999084472656", font_gabarito_semibold_40_959999084472656);
    lv_xml_register_font(NULL, "font_gabarito_regular_19_19999885559082", font_gabarito_regular_19_19999885559082);
    lv_xml_register_font(NULL, "font_gabarito_semibold_19_19999885559082", font_gabarito_semibold_19_19999885559082);
    lv_xml_register_font(NULL, "font_gabarito_regular_15_359999656677246", font_gabarito_regular_15_359999656677246);
    lv_xml_register_font(NULL, "font_gabarito_semibold_33_279998779296875", font_gabarito_semibold_33_279998779296875);
    lv_xml_register_font(NULL, "font_gabarito_semibold_28_15999984741211", font_gabarito_semibold_28_15999984741211);
    lv_xml_register_font(NULL, "font_gabarito_semibold_43_52000045776367", font_gabarito_semibold_43_52000045776367);
    lv_xml_register_font(NULL, "font_gabarito_medium_14_079999923706055", font_gabarito_medium_14_079999923706055);
    lv_xml_register_font(NULL, "font_gabarito_semibold_24_576000213623047", font_gabarito_semibold_24_576000213623047);
    lv_xml_register_font(NULL, "font_gabarito_regular_24_576000213623047", font_gabarito_regular_24_576000213623047);
    lv_xml_register_font(NULL, "font_gabarito_medium_21_29920196533203", font_gabarito_medium_21_29920196533203);
    lv_xml_register_font(NULL, "font_gabarito_semibold_36_0447998046875", font_gabarito_semibold_36_0447998046875);
    lv_xml_register_font(NULL, "font_gabarito_bold_168_95999145507812", font_gabarito_bold_168_95999145507812);
    lv_xml_register_font(NULL, "font_gabarito_medium_56_31999969482422", font_gabarito_medium_56_31999969482422);
    lv_xml_register_font(NULL, "font_gabarito_semibold_23_03999900817871", font_gabarito_semibold_23_03999900817871);
    lv_xml_register_font(NULL, "font_gabarito_semibold_30_719999313354492", font_gabarito_semibold_30_719999313354492);
    lv_xml_register_font(NULL, "font_gabarito_regular_16_639999389648438", font_gabarito_regular_16_639999389648438);
    lv_xml_register_font(NULL, "font_gabarito_regular_14_079999923706055", font_gabarito_regular_14_079999923706055);
    lv_xml_register_font(NULL, "font_gabarito_medium_16_639999389648438", font_gabarito_medium_16_639999389648438);
    lv_xml_register_font(NULL, "font_gabarito_semibold_25_599998474121094", font_gabarito_semibold_25_599998474121094);
    lv_xml_register_font(NULL, "font_gabarito_medium_19_19999885559082", font_gabarito_medium_19_19999885559082);
    lv_xml_register_font(NULL, "font_gabarito_medium_15_359999656677246", font_gabarito_medium_15_359999656677246);
    lv_xml_register_font(NULL, "font_gabarito_medium_16_64000129699707", font_gabarito_medium_16_64000129699707);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_alert_volume", &subject_alert_volume);
    lv_xml_register_subject(NULL, "subject_bay_reserve", &subject_bay_reserve);
    lv_xml_register_subject(NULL, "subject_cable_thermal", &subject_cable_thermal);
    lv_xml_register_subject(NULL, "subject_card_ending", &subject_card_ending);
    lv_xml_register_subject(NULL, "subject_chg_limit", &subject_chg_limit);
    lv_xml_register_subject(NULL, "subject_chg_pct", &subject_chg_pct);
    lv_xml_register_subject(NULL, "subject_contactless", &subject_contactless);
    lv_xml_register_subject(NULL, "subject_current_cost", &subject_current_cost);
    lv_xml_register_subject(NULL, "subject_km_added", &subject_km_added);
    lv_xml_register_subject(NULL, "subject_power_stage", &subject_power_stage);
    lv_xml_register_subject(NULL, "subject_preferences_modal_state", &subject_preferences_modal_state);
    lv_xml_register_subject(NULL, "subject_screen_brightness", &subject_screen_brightness);
    lv_xml_register_subject(NULL, "subject_time", &subject_time);
    lv_xml_register_subject(NULL, "subject_wifi", &subject_wifi);
    lv_xml_register_subject(NULL, "subject_unbound_card_bay_bar", &subject_unbound_card_bay_bar);
    lv_xml_register_subject(NULL, "subject_unbound_card_bay_value_card_bay_2", &subject_unbound_card_bay_value_card_bay_2);
    lv_xml_register_subject(NULL, "subject_unbound_field_slider_control_slider", &subject_unbound_field_slider_control_slider);
    lv_xml_register_subject(NULL, "subject_unbound_field_slider_value_field_slider_2", &subject_unbound_field_slider_value_field_slider_2);
    lv_xml_register_subject(NULL, "subject_unbound_row_toggle_control_switch", &subject_unbound_row_toggle_control_switch);
    lv_xml_register_subject(NULL, "subject_unbound_tile_stat_value_tile_stat_2", &subject_unbound_tile_stat_value_tile_stat_2);
    lv_xml_register_subject(NULL, "subject_language_id", &subject_language_id);
    lv_xml_register_subject(NULL, "subject_animations", &subject_animations);

    /* Register callbacks */
    lv_xml_register_event_cb(NULL, "charge_screen_events_cb", charge_screen_events_cb);
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if defined(LV_USE_XML) && LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "image_qr_receipt_115x115", image_qr_receipt_115x115);
    lv_xml_register_image(NULL, "image_qr_receipt_64x64", image_qr_receipt_64x64);
    lv_xml_register_image(NULL, "image_plug_large", image_plug_large);
    lv_xml_register_image(NULL, "image_back_byd_1039x365", image_back_byd_1039x365);
    lv_xml_register_image(NULL, "image_back_byd_755x265", image_back_byd_755x265);
    lv_xml_register_image(NULL, "image_back_byd_425x149", image_back_byd_425x149);
    lv_xml_register_image(NULL, "image_4", image_4);
    lv_xml_register_image(NULL, "image_front_byd", image_front_byd);
    lv_xml_register_image(NULL, "image_icon_supercharge_green_24419", image_icon_supercharge_green_24419);
    lv_xml_register_image(NULL, "image_icon_zap_19913", image_icon_zap_19913);
    lv_xml_register_image(NULL, "image_icon_plug_19916", image_icon_plug_19916);
    lv_xml_register_image(NULL, "image_icon_supercharge", image_icon_supercharge);
    lv_xml_register_image(NULL, "image_icon_nfc_19919", image_icon_nfc_19919);
    lv_xml_register_image(NULL, "image_vec_263_32", image_vec_263_32);
    lv_xml_register_image(NULL, "image_icon_diagnostic_323653", image_icon_diagnostic_323653);
    lv_xml_register_image(NULL, "image_icon_settings_1988", image_icon_settings_1988);
    lv_xml_register_image(NULL, "image_vec_263_263", image_vec_263_263);
    lv_xml_register_image(NULL, "image_icon_back_323661", image_icon_back_323661);
    lv_xml_register_image(NULL, "image_icon_close_30435", image_icon_close_30435);
    lv_xml_register_image(NULL, "image_vec_270_4", image_vec_270_4);
    lv_xml_register_image(NULL, "image_vec_270_5", image_vec_270_5);
    lv_xml_register_image(NULL, "image_vec_270_6", image_vec_270_6);
    lv_xml_register_image(NULL, "image_vec_270_7", image_vec_270_7);
    lv_xml_register_image(NULL, "image_vec_270_8", image_vec_270_8);
    lv_xml_register_image(NULL, "image_lucide_nfc", image_lucide_nfc);
    lv_xml_register_image(NULL, "image_vec_273_184", image_vec_273_184);
    lv_xml_register_image(NULL, "image_vec_273_185", image_vec_273_185);
    lv_xml_register_image(NULL, "image_vec_273_186", image_vec_273_186);
    lv_xml_register_image(NULL, "image_vec_328_444", image_vec_328_444);
    lv_xml_register_image(NULL, "img_wheel_base", img_wheel_base);
    lv_xml_register_image(NULL, "img_wheel_rim", img_wheel_rim);
    lv_xml_register_image(NULL, "img_wheel_base_98", img_wheel_base_98);
    lv_xml_register_image(NULL, "img_wheel_rim_98", img_wheel_rim_98);
#endif

#if !defined(LV_USE_XML) || LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manually from XML using lv_xml_create() */
#endif
}

void lvpower_set_target(uint32_t target)
{
    lvpower_target = target;
}

uint32_t lvpower_get_target(void)
{
    return lvpower_target;
}

bool lvpower_check_target(uint32_t target)
{
    return (lvpower_target & target) ? true : false;
}

/* Callbacks */
#if defined(LV_EDITOR_PREVIEW)
void __attribute__((weak)) charge_screen_events_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("charge_screen_events_cb was called\n");
}
#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void check_font(lv_font_t ** font, const char * name)
{
    if (!(*font)) {
        *font = (lv_font_t *)LV_FONT_DEFAULT;
        LV_LOG_WARN("font `%s` was not set. Using `LV_FONT_DEFAULT` instead", name);
    }
}