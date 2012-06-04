$(document).ready(function(){
	var globalIndexUrl = '/cgi-bin/GlobalIndex';

	getGlobalIndex(globalIndexUrl);
});

function getGlobalIndex(url) {
	var random_id = Math.round(Math.random()*1000000000);
	$.ajax({
		url: url,
		contentType: 'text/xml',
		data: "<Search name='request_"+random_id+"' id='"+random_id+"'><Filters><Filter name='CPU-Frequency'/><Filter name='MEM-Count' /><Filter name='OS-Name' /></Filters><Data><Comparetype='OR'><Compare type='AND'><Atrybute name='CPU-Frequency' compType='>='value='1000' /><Atrybute name='CPU-Frequency' compType='<=' value='1500'/></Compare><Atrybute name='MEM-Count' compType='>=' value='4000'/></Compare></Data></Search>",
		dataType: 'text',
		type: 'post',
		error: onGetGlobalIndexError,
		success: onGetGlobalIndexSuccess
	});
}

function getGlobalIndexList(url) {
        $.ajax({
                url: url,
                dataType: 'xml',
                type: 'get',
                error: onGetGlobalIndexError,
                success: onGetGlobalIndexSuccess
        });
}

function onGetGlobalIndexError(jqXHR, textStatus, errorThrown) {
	console.error('onGetGlobalIndexError('+textStatus+'): '+errorThrown);
	console.info('Response headers:\n\n'+jqXHR.getAllResponseHeaders());

	var location = jqXHR.getResponseHeader('Location');
	if (location !== null) {
		getGlobalIndexList(location);
	}
}

function onGetGlobalIndexSuccess(data, textStatus, jqXHR) {
	var location = jqXHR.getResponseHeader('Location');
	if (location !== null) {
		getResources(location);
	}
}

/**
 * Get resources from URL.
 * 
 * @param string resourcesUrl String containing URL to the resources list
 */
function getResources(resourcesUrl) {
	$.ajax({
		url: resourcesUrl,
		dataType: 'xml',
		type: 'get',
		error: onGetResourcesError,
		success: onGetResourcesSuccess
	});
}

/**
 * getResources error handler
 *  
 * @see getResources
 */
function onGetResourcesError(jqXHR, textStatus, errorThrown) {
	alert(textStatus);
}

/**
 * getResources success handler
 * 
 * Creates markup to show resources list
 * 
 * @see getResources
 */
function onGetResourcesSuccess(data, textStatus, jqXHR) {
	var $list = $('#resources-list');
	var $data = $(data);
	var $resources = $data.find('Monitor');
	
	if ($resources.size() > 0) {
		$resources.each(function(i, item){
			var $item = $(this);
			//var id = $item.attr('href').split('/').pop();
			var id = i;
			
			var $listItem = $('<dt>')
				.attr('id', 'resource-' + id)
				.attr('data-toggle', 'collapse')
				.attr('data-target', '#resource-' + id + ' + dd')
				.text($item.attr('name')).
				on('click', toggleToggleIcon);
				
			var $icon = $('<i>')
				.addClass('icon-plus-sign')
			$icon.prependTo($listItem);
			
			var $attrs = $item.find('Atrybute');
			if ($attrs.size() > 0) {
				$listItem.appendTo($list);
				
				var $descr = $('<dd>').addClass('collapse');
				var $ul = $('<ul>');
				$attrs.each(function(){
					var $item = $(this);
					var $li = $('<li>');
					$li.text($item.attr('name') + ' (' + $item.attr('compType') + '): ' + $item.attr('value'));
					$li.appendTo($ul);
				});
				$ul.appendTo($descr);
				$descr.appendTo($list);
			}
		});
		
		$list.parents('div').removeClass('collapse');
	}
}

/**
 * Toggles 'toggle' icon
 * 
 * @see onGetResourcesSuccess
 */
function toggleToggleIcon() {
	$icon = $(this).find('i[class^=icon]');

	// do action if only one icon found (can be changed to .each loop instead)
	// and it is either icon-plus-sign or icon-minus-sign
	if (
		$icon.size() == 1 && 
		$icon.is('.icon-plus-sign, .icon-minus-sign')
	) {
		$icon.toggleClass('icon-plus-sign icon-minus-sign');
	}
}